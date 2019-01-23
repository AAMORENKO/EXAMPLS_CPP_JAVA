import java.io.*;
import java.util.*;

public class OrderMatrixComb {

    public static void main(String[] args) {

        System.out.println("\n\tОбъеденяем две таблицы в одну A+B=C\n");

        int n=10;
        int [] A=new int[n];
        int [] B=new int[n];
        int [] C=new int[2*n];


        int k=0;
        for (int i = 0; i <n ; i++) {
            A[i]=(int)(99*Math.random());
            B[i]=(int)(99*Math.random());
            C[k]=A[i]; C[k+1]=B[i];
            k+=2;
        }

        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);

        for (int i = 0; i <n; i++) {
            System.out.printf("A[%d]=%d  ",i,A[i]);
        }
        System.out.println("\n");

        for (int i = 0; i <n; i++) {
            System.out.printf("B[%d]=%d  ",i,B[i]);
        }
        System.out.println("\n");


        for (int i = 0; i <2*n; i++) {
            System.out.printf("C[%d]=%d\n",i,C[i]);
        }
        System.out.println("\n");


    }
}
