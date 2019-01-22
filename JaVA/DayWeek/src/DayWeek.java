import java.io.*;
import java.util.*;

public class DayWeek {

    public static void main(String[] args) {

        System.out.println("Определяем тим дня недели этого года\n\n");
        int d,m,c,y;

        c=21;
        y=19;

        Scanner in = new Scanner(System.in);
        System.out.print("Введите день: ");
        d=in.nextInt();
        System.out.print("Введите месяц: ");
        m=in.nextInt();

        int res=(d+(int)((13*m-1)/5)+y+(int)(y/4)+(int)(c/4)-2*c+777)%7;
        String txt="";

        switch (res)
        {
            case 0: txt="\nЭтот день выходной. Воскресенье."; break;
            case 1: txt="\nЭто рабочий день. Понедельник."; break;
            case 2: txt="\nЭто рабочий день. Вторник."; break;
            case 3: txt="\nЭто рабочий день. Среда."; break;
            case 4: txt="\nЭто рабочий день. Четверг."; break;
            case 5: txt="\nЭто рабочий день. Пятница."; break;
            case 6: txt="\nЭтот день выходной. Суббота."; break;

            default: txt="\nОшибка ввода. Такого дня нет.";
        }

        System.out.println("\t"+txt);

    }
}
