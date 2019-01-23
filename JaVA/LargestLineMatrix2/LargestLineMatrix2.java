import java.io.*;
import java.util.*;

public class LargestLineMatrix2 {
    public static void main(String[] args) {

        System.out.println("\nПоиск номера строки с наибольшей суммой\n");

        int n=10;
        int [][] A=new int[n][n];
        int [] S=new int [n];

        for (int i = 0; i <n ; i++) {
            S[i]=0;
        }

        for (int i = 0; i <n ; i++) {
            for (int j = 0; j <n ; j++) {
                A[i][j]=(int)(99*Math.random());
                System.out.printf("%4d",A[i][j]);
                S[i]+=A[i][j];
            }
            System.out.printf("  сумма элементов в строке равна S[%d]=%d\n",i,S[i]);
        }


        int num=0;
        int max=S[num];
        for (int i = 0; i <n; i++) {
            if(max<S[i])
            {
                max=S[i];
                num=i;
            }
        }

        System.out.printf("\n\n\tНаибольшая сумма в строке с номером %d\n\n",num+1);

    }
}
