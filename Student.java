package assignment1;
import java.util.*;

public class Student {
    Name name;
    Address address;
    Date date;
    ArrayList<String> courses = new ArrayList<String>(5);
    String Id;
    
    public Name getName(){
        return name;
    }
    
    public Address getAddress(){
        return address;
    }
    
    public void setName(String first, String last){
        this.name.setFirst(first);
        this.name.setLast(last);
    }
    
    public void addCourse(String courseId){
        courses.add(courseId);
    }
    
    public void dropCourse(String courseId){
        for(int x = 0; x < courses.size(); x++)
            if(courses.get(x).equals(courseId)) courses.remove(x);
    }
    
}
