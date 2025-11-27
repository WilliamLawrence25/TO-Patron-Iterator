class IteradorBase {
    private String[] array;
    private int cursor = 0;

    public IteradorBase(String[] array) {
        this.array = array;
    }

    public boolean has_next() {
        return cursor < array.length;
    }

    public String next() {
        return array[cursor++];
    }
}

public class Iterador {
    public static void main(String[] args) {
        String[] dias = {"lunes", "martes", "miércoles", "jueves", "viernes"};
        IteradorBase it = new IteradorBase(dias);

        while (it.has_next()) {
            System.out.println("Todavía queda un elemento: " + it.next());
        }

        System.out.println("Ya he terminado");
    }
}
