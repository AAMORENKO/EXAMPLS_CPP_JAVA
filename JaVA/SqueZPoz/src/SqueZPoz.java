import java.io.*;
import java.util.*;

public class SqueZPoz {

    public static void main(String[] args) {

        System.out.println("Печатаем таблицу квадратов целых положительных нечетных чисел");

        int k,p;
        for (int i = 0; i <10 ; i++) {

            k=i+1; p=k*k;
            if(k%2!=0) System.out.printf("\n\tчисло %3d в квадрате равно %3d",k,p);

        }
    }
}

