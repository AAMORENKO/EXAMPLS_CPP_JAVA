import java.io.*;
import java.util.*;
import javax.swing.*;

public class ParneNumber {

    public static void main(String[] args) {

        int number=Integer.parseInt(JOptionPane.showInputDialog("Введите число:"));
        String text=(number%2==0?"четное":"нечетное");
        JOptionPane.showMessageDialog(null,"Вы ввели "+text+" число!");

    }

}
