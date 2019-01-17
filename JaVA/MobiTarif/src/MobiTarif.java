import java.io.*;
import java.util.*;
import javax.swing.*;


public  class MobiTarif {

    public static void main(String[] args) {

        String text="";

        double tarif=1.5f;

        int n=Integer.parseInt(JOptionPane.showInputDialog("Вычисление стоимости разговора по телефону\nВведите исходные данные:\nДлительность разговора (целое количество минут)"));
        int d=Integer.parseInt(JOptionPane.showInputDialog("Вычисление стоимости разговора по телефону\nВведите исходные данные:\nдень недели (1 - пн, 2- вт, ... 7 - вс)"));

        double summ=0;
        if(d>5){
            summ=tarif*n*0.8;
            text+="\nПредоставляется скидка 20%\n";
        } else summ=tarif*n;

        text+="Вы разговаривали "+n+" минут и стоимость: "+summ +" грн.";

        JOptionPane.showMessageDialog(null,text);
    }
}