
package assignment1;
import java.util.*;

public class Admissions {
    ArrayList<Student> admissions = new ArrayList<Student>();
    ArrayList<Student> dropped = new ArrayList<Student>();
    
    public void addStudent(Student std){
        admissions.add(std);
    }
    
    public boolean checkStudent(String Id){
        for(int x = 0; x < admissions.size(); x++){
            if(admissions.get(x).Id.equals(Id))
                return true;
        }
        return false;
    }
    
    public String showAdmissions(){
        
        String output = "";
        String message = "";
        String courses = "";
        for(int x = 0; x < admissions.size(); x++){
            message = "Student Name: " + admissions.get(x).name.last + "," +admissions.get(x).name.first + "\n" + 
                   "Student Address: " + admissions.get(x).address.street + " " + admissions.get(x).address.city + " " + admissions.get(x).address.state + " " + admissions.get(x).address.zipcode + "\n" + 
                    "Student ID:" + admissions.get(x).Id + "\n" 
                    +"Enrolled Courses: ";
            for(int y = 0; y < admissions.get(x).courses.size(); y++){
                courses = courses + admissions.get(x).courses.get(y) + "\n";
            }
            output = output + message + courses + "\n";
        }
        return output;
    }
    
    public String showDropped(){
         
        String output = "";
        String message = "";
        String courses = "";
        for(int x = 0; x < dropped.size(); x++){
            message = "Student Name: " + dropped.get(x).name.last + "," +dropped.get(x).name.first + "\n" + 
                   "Student Address: " + dropped.get(x).address.street + " " + dropped.get(x).address.city + " " + dropped.get(x).address.state + " " + dropped.get(x).address.zipcode + "\n" + 
                    "Student ID:" + dropped.get(x).Id + "\n" 
                    +"Enrolled Courses: ";
            for(int y = 0; y < dropped.get(x).courses.size(); y++){
                courses = courses + dropped.get(x).courses.get(y);
            }
            output = output + message + courses + "\n";
        }
        return output;
    }
    
    public void removeStudent(String id){
        for(int a = 0; a < admissions.size(); a++){
            if(admissions.get(a).Id.equals(id)){
                dropped.add(admissions.get(a));
                admissions.remove(a);
            }    
        }
    }
}
