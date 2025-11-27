class Iterador:
    def __init__(self, array):
        self.array = array
        self.cursor = 0

    def next(self):
        item = self.array[self.cursor]
        self.cursor += 1
        return item

    def has_next(self):
        return self.cursor < len(self.array)


# Ejemplo de uso
array = ['lunes', 'martes', 'miércoles', 'jueves', 'viernes']
it = Iterador(array)

while it.has_next():
    print("Todavía queda un elemento: " + it.next())

print("Ya he terminado")
