import java.io.*;
import java.util.*;

public class DayWeek {

    public static void main(String[] args) {

        System.out.println("Определяем тип дня недели этого года\n\n");
        int D,M,Y;

        Y=19; // порядковый номер года, например 19 из 2019

        Scanner in = new Scanner(System.in);
        System.out.print("Введите день: ");
        D=in.nextInt();
        System.out.print("Введите месяц: ");
        M=in.nextInt();


        int a,y,m;
        String txt = "";
        int res=0;

        if((D>0 && D<32)&&(D!=29 && M==2))
        {
            a = (14 - M) / 12;
            y = Y - a;
            m = M + 12 * a - 2;
            res = 7000 + (D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
            res = res % 7;

            switch (res)
            {
                case 0:
                    txt = "\nЭтот день выходной. Воскресенье.";
                    break;
                case 1:
                    txt = "\nЭто рабочий день. Понедельник.";
                    break;
                case 2:
                    txt = "\nЭто рабочий день. Вторник.";
                    break;
                case 3:
                    txt = "\nЭто рабочий день. Среда.";
                    break;
                case 4:
                    txt = "\nЭто рабочий день. Четверг.";
                    break;
                case 5:
                    txt = "\nЭто рабочий день. Пятница.";
                    break;
                case 6:
                    txt = "\nЭтот день выходной. Суббота.";
                    break;
            }
        } else  txt = "\nОшибка ввода. Такого дня нет.";

        System.out.println("\t"+txt);

    }
}