import java.io.*;
import java.util.*;
import javax.swing.*;


public  class TarifMobi {

    public static void main(String[] args) {


        int n=Integer.parseInt(JOptionPane.showInputDialog("Вычисляем стоимость разговора\nВведите исходные данные\nДлительность разговора в минутах (целочисленное число)"));

        int d=Integer.parseInt(JOptionPane.showInputDialog("Вычисляем стоимость разговора\nВведите исходные данные\nДень недели (1 - пн, 2 - вт, ... , 7 - вс)"));

        String text="";
        double tarif;
        tarif = 1.5f;

        double summ=0;

        if(d>5) {
            summ=tarif*n*0.8f;
            text+="\nПредоставляется скидка 20%\n";
        } else summ=tarif*n;

       String ms = String.format("%6.2f",summ);

        text+="Стоимость разговора ";
        text+=(ms+" грн.");



        JOptionPane.showMessageDialog(null,text);
    }
}