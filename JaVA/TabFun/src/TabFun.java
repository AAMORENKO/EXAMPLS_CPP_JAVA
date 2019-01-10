import java.io.*;
import java.util.*;

public class TabFun {

  public static void main(String[] args) {
      System.out.println("\nТаблица функции y=f(x), [a;b]");
      double x,y,h;
      double a,b;

      Scanner in = new Scanner(System.in);
      System.out.print("Введите a=");
      a=in.nextDouble();
      System.out.print("Введите b=");
      b=in.nextDouble();
      h=Math.abs(b-a)/10.0f;
      x=a;
      while(x<=b){
        y=-2.7f*x*x*x+0.23f*x*x-1.4f;
        System.out.printf("x=%4.3f\ty=%8.6f\n",x,y);
        x=x+h;
        }

      }
}