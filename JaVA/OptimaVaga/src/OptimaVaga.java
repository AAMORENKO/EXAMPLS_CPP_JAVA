import java.io.*;
import java.util.*;
import javax.swing.*;


public  class OptimaVaga {

    public static void main(String[] args) {


        int rost=Integer.parseInt(JOptionPane.showInputDialog("Введите свой рост в см:"));
        int ves=Integer.parseInt(JOptionPane.showInputDialog("Введите свой вес в кг:"));

        int raznost; raznost=rost-100;
        int vaga=raznost-ves;

        String text=(vaga<0?"Вы перебрали на "+Math.abs(vaga)+" кг":"Вы не добрали "+Math.abs(vaga)+" кг");

        JOptionPane.showMessageDialog(null,"Ваш результат: "+text);

    }

}
