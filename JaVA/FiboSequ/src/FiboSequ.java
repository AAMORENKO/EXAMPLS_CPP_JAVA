import java.io.*;

public class FiboSequ {
    public static void main(String[] args) {
        System.out.println("Числа Фібоначі:\n" +
                "\n");
        long x1;
        x1 = 1;
        long x2=1;
        long x=x1+x2;
        System.out.print(x1+" "+x2+" "+x+" ");
        int n=3;
        while(n<29)
        {
            x1=x2;
            x2=x;
            x=x2+x1;
            System.out.print(x+" ");
            n++;
        }

    }

}