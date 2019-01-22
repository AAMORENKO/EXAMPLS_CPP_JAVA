import java.io.*;
import java.util.*;

public class RepeatFam {

    public static void main(String[] args) {

        System.out.println("Печатаем фамилию имя в цикле\n\n");
        String fam,name;
        fam=name="";

        Scanner in = new Scanner(System.in);
        System.out.print("Введите Вашу фамилию: ");
        fam=in.nextLine();
        System.out.print("Введите Ваше имя: ");
        name=in.nextLine();

        for (int i = 0; i <10 ; i++) {
            System.out.println("\t"+(i+1)+") "+fam+" "+name);
        }
    }
}
