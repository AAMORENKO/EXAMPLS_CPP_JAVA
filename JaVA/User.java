import java.io.*;
import java.util.*;

public class User {
    private int id;
    private String name;
    private String site;

    public User(int id, String name, String site) {
        this.id = id;
        this.name = name;
        this.site = site;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getSite() {
        return site;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        User user = (User) o;
        return id == user.id &&
                Objects.equals(name, user.name) &&
                Objects.equals(site, user.site);
    }

    @Override
    public int hashCode() {

        return Objects.hash(id, name, site);
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", site='" + site + '\'' +
                '}';
    }
}