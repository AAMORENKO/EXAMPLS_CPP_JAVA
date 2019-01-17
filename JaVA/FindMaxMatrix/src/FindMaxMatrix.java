import java.io.*;
import java.util.*;
import javax.swing.*;


public  class FindMaxMatrix {

    public static void main(String[] args) {


        int n=Integer.parseInt(JOptionPane.showInputDialog("Введите число N="));

        String text="";

        int [][] A=new int[n][n];

        for (int i = 0; i <n; i++) {
            text+="\n";
            for (int j = 0; j <n ; j++) {
                int p=-1;
                for (int k = 0; k <10*Math.random(); k++) p*=(-1);
                A[i][j]=(int)(10+89*Math.random())*p;
                if(A[i][j]>0)
                {
                    text+="   "+A[i][j];
                }else
                {
                    text+=A[i][j]+"  ";
                }

            }
        }

        int max=A[0][0];
        for (int i = 0; i <n; i++) {
            for (int j = 0; j <n; j++) {
                if (A[i][j]>max) max=A[i][j];
            }
        }

        text+="\n\n";
        text+="Наибольшее число: "+max+"\n";

        int kl=0;
        for (int i = 0; i <n; i++) {
            for (int j = 0; j <n; j++) {
                if(A[i][j]==max) kl++;
            }
        }


        text+="в количестве "+kl;

        JOptionPane.showMessageDialog(null,"Ваша таблица Matrix:\n\n"+text);
    }
}