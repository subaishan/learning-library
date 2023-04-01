package IOwork5;

import java.io.Serial;
import java.io.Serializable;

public class student implements Serializable {
    @Serial
    private static final long serialVersionUID = -4392406017290377670L;
    private int age;
    private String name;

    public student(int _age,String _name){
        this.age = _age;
        this.name = _name;
    }

    public String toString(){
        return "student{name = "+name+", age = "+age+"}";
    }
}
