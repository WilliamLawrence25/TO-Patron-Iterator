# Implementación del Patrón Iterator

Este repositorio contiene implementaciones del **Patrón de Diseño Iterator** en **C++**, **Java** y **Python**, junto con una explicación completa del patrón, sus componentes principales y una comparación con patrones similares.

---

## 📌 Descripción General

El **Patrón Iterator** es un patrón de diseño de comportamiento que permite recorrer elementos de una colección **sin exponer su estructura interna**, proporcionando una interfaz uniforme para recorrer distintos tipos de colecciones.

Este patrón:
- Separa la lógica de recorrido del contenedor.
- Permite múltiples formas de iterar una misma colección.
- Aumenta la cohesión del código.
- Reduce el acoplamiento entre estructuras de datos y sus recorridos.

---

## 🧩 Componentes del Patrón

- **Iterator**: Interfaz que define los métodos de recorrido (`getNext()`, `hasMore()`).
- **ConcreteIterator**: Implementa la lógica de iteración manteniendo el estado interno y una referencia a la colección.
- **IterableCollection**: Interfaz que define el método para crear un iterador (`createIterator()`).
- **ConcreteCollection**: Implementa la colección y crea una instancia del iterador correspondiente.


![Diagrama UML](docs/iterator_uml.png)

---

# 🐍Ejemplo en Python

Este ejemplo fue mostrado en diapositivas y es la base para los otros lenguajes.

```python
class Iterator:
    def has_next(self):
        pass

    def next(self):
        pass


class ConcreteIterator(Iterator):
    def __init__(self, collection):
        self._collection = collection
        self._index = 0

    def has_next(self):
        return self._index < len(self._collection)

    def next(self):
        if self.has_next():
            value = self._collection[self._index]
            self._index += 1
            return value
        raise StopIteration


class Aggregate:
    def create_iterator(self):
        pass


class ConcreteAggregate(Aggregate):
    def __init__(self, items):
        self.items = items

    def create_iterator(self):
        return ConcreteIterator(self.items)


if __name__ == "__main__":
    collection = ConcreteAggregate([1, 2, 3, 4, 5])
    iterator = collection.create_iterator()

    while iterator.has_next():
        print(iterator.next())
```

---

# 💻Ejemplo equivalente en C++

```cpp
#include <iostream>
#include <vector>

class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

class ConcreteIterator : public Iterator {
private:
    std::vector<int> collection;
    int index = 0;

public:
    ConcreteIterator(const std::vector<int>& c) : collection(c) {}

    bool hasNext() override {
        return index < collection.size();
    }

    int next() override {
        return collection[index++];
    }
};

class Aggregate {
public:
    virtual Iterator* createIterator() = 0;
};

class ConcreteAggregate : public Aggregate {
private:
    std::vector<int> items;

public:
    ConcreteAggregate(std::vector<int> v) : items(v) {}

    Iterator* createIterator() override {
        return new ConcreteIterator(items);
    }
};

int main() {
    ConcreteAggregate agg({1, 2, 3, 4, 5});
    Iterator* it = agg.createIterator();

    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
}
```

---

# ☕ Ejemplo equivalente en Java

```java
import java.util.*;

interface IteratorCustom {
    boolean hasNext();
    int next();
}

class ConcreteIterator implements IteratorCustom {
    private List<Integer> collection;
    private int index = 0;

    public ConcreteIterator(List<Integer> c) {
        this.collection = c;
    }

    public boolean hasNext() {
        return index < collection.size();
    }

    public int next() {
        return collection.get(index++);
    }
}

interface Aggregate {
    IteratorCustom createIterator();
}

class ConcreteAggregate implements Aggregate {
    private List<Integer> items;

    public ConcreteAggregate(List<Integer> items) {
        this.items = items;
    }

    public IteratorCustom createIterator() {
        return new ConcreteIterator(items);
    }
}

public class Main {
    public static void main(String[] args) {
        ConcreteAggregate agg = new ConcreteAggregate(Arrays.asList(1,2,3,4,5));
        IteratorCustom it = agg.createIterator();

        while(it.hasNext()) {
            System.out.println(it.next());
        }
    }
}
```

---

# 📚 Comparación con otros patrones

| Patrón | Parecido | Diferencia clave |
|-------|----------|------------------|
| **Iterator** | Recorre colecciones sin exponerlas | No controla cómo se almacena, solo cómo se recorre |
| **Visitor** | Recorre elementos | Aplica operaciones a cada elemento, no se enfoca en el recorrido |
| **Composite** | Trabaja con colecciones estructuradas | No define cómo iterar, solo cómo agrupar |
| **Strategy** | Separa un algoritmo | Iterator separa solo la lógica de recorrido |

---

# 🎯 Casos de Uso Reales

- Recorrer listas, colas, pilas, árboles, grafos.
- APIs de colecciones (Java Collections, C++ STL, Python iterators).
- Recorrer recursos externos (archivos, streams, sockets).
- Implementar iteraciones personalizadas (inversas, filtradas, ordenadas).

---

# 📌 Propósito del Repositorio

Este repositorio sirve para:

- Comprender los componentes del patrón Iterator.
- Comparar la implementación en tres lenguajes distintos.
- Tener una referencia clara para exposiciones y trabajos académicos.
- Mostrar similitudes y diferencias entre paradigmas.

---

# ✔️ Estructura del Repositorio

```
TO-PATRON-ITERATOR/
│── cpp/
│   └── iterator.cpp
│── java/
│   └── Main.java
│── python/
│   └── iterator.py
│── README.md
└── docs/
      └── iterator_uml.png
```

---

# 🙌 Conclusión

El patrón Iterator ayuda a recorrer colecciones de forma flexible, limpia y desacoplada.  
Su uso es tan común que muchos lenguajes lo tienen integrado de forma nativa (como `__iter__` en Python o `Iterator` en Java).

