import java.io.*;
import java.util.*;


public class Main {

    public static void main(String[] args) {
        List<User> users = new ArrayList<>();

        users.add(new User(1, "Виталий", "facebook.com"));
        users.add(new User(2, "Михаил", "facebook.com"));
        users.add(new User(3, "Александр", "facebook.com"));
        users.add(new User(4, "Илья", "twitter.com"));
        users.add(new User(5, "Святослав", "twitter.com"));
        users.add(new User(6, "Дмитрий", "twitter.com"));
        users.add(new User(7, "Пётр", "twitter.com"));


        Map<String, Integer> statistic = new HashMap<>();
        for (User user : users) {
            String site = user.getSite();

            Integer count = statistic.get(site);

            if(count == null) {
                statistic.put(site, 1);
            } else {
                Integer newCount = count + 1;
                statistic.put(site, newCount);
            }
        }

        for (Map.Entry<String, Integer> entry : statistic.entrySet()) {
            System.out.println(entry.getKey() + " - " + entry.getValue());
        }
    }
}