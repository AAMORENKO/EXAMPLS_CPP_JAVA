import java.io.*;
import java.util.*;

public class RectArea {
        public static void main(String[] args) {
            System.out.println("Вычисляем площадь прямоугольника");
            double a,b,s;

            Scanner in = new Scanner(System.in);
            System.out.print("Введите длину a=");
            a=in.nextDouble();
            System.out.printf("длина a=%3.2f\n",a);
            System.out.print("Введите ширину b=");
            b=in.nextDouble();
            System.out.printf("ширина b=%3.2f\n",b);

            s=a*b;

            System.out.printf("Площадь равна S=%8.4f кв.ед.\n",s);
        }
}