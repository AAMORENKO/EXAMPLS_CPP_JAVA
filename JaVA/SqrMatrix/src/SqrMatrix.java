import java.io.*;
import java.util.*;
import javax.swing.*;


public  class SqrMatrix {

    public static void main(String[] args) {


        int n=Integer.parseInt(JOptionPane.showInputDialog("Введите число N="));

        String text="";

        int [][] A=new int[n][n];

        for (int i = 0; i <n; i++) {
            text+="\n";
            for (int j = 0; j <n ; j++) {
                A[i][j]=(int)(10+89*Math.random());
                text+=A[i][j]+" ";
            }
        }
        JOptionPane.showMessageDialog(null,"Ваша таблица Matrix:\n\n"+text);
    }
}
