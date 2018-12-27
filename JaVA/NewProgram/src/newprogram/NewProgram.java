package newprogram;

/*
import javax.swing.*;
 */
public class NewProgram {

    public static void main(String[] args) {

        // 1 - JOptionPane.showMessageDialog(null, "Всем ПРИВЕТ!");

        // 2 -
        System.out.println("Всем ПРИВЕТ");

        /* 3 -
        String name;
        name=JOptionPane.showInputDialog("Доброго дня. Як Вас звуть?");
        JOptionPane.showMessageDialog(null, "Дуже приємно познайомитись, "+name+"!");
        */

        /* 4-
        int Number=321;
        String NotANumber="123";
        int ANumber=Integer.parseInt(NotANumber);
        String titlel="Команда Number+NotANumber";
        String title2="Команда Number+ANumber";
        int typel=JOptionPane.ERROR_MESSAGE;
        int type2=JOptionPane.WARNING_MESSAGE;
        JOptionPane.showMessageDialog(null,Number+NotANumber,titlel,typel);
        JOptionPane.showMessageDialog(null,Number+ANumber,title2,type2);
        */

        /* 5-
        int number=Integer.parseInt(JOptionPane.showInputDialog("Введите число:"));
        String text=number%2==0?"четное":"нечетное";
        JOptionPane.showMessageDialog(null,"Вы ввели "+text+" число!");
        */


    }

}
