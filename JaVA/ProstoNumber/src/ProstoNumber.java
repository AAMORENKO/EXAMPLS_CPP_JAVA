import java.io.*;
import java.util.*;
import javax.swing.*;


public  class ProstoNumber {

    public static void main(String[] args) {


        int n=Integer.parseInt(JOptionPane.showInputDialog("Введите число N="));
        int a=1;
        int d,i;

        String text="";

        for (i = 0; i<n ; i++) {
            a++;
            d=1;
            do {
                d++;
            } while(a%d!=0);
            if(a==d)
            {
                text+=a+" ";
            }
        }
        JOptionPane.showMessageDialog(null,"Ваш результат:\n\n"+text);
    }
}
