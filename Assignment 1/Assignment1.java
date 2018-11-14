package assignment1;
import javax.swing.*;
import java.lang.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Assignment1 {

    
    public static void main(String[] args) {
        
        
        GetData data = new GetData();
        JFrame frame = new JFrame();
        JTextArea textarea = new JTextArea();
        JScrollPane scrollpane = new JScrollPane(textarea);
        
        Admissions fall = new Admissions(); 
        
        Object[] options = {"Add a student", "Change a student's record", "Remove a student from the database", "List Currently Registered Students", "List Dropped Students", "Exit"};
        
        String s;    
        
        do{
            s = (String)JOptionPane.showInputDialog(frame, "What would you like to do? ", "Assignment 1", JOptionPane.PLAIN_MESSAGE, null, options, "Add a student");
            
            if(s == null) break;
            
            if(s.equals("Add a student")){
                Student test = new Student();

                test.Id = data.getWord("Enter the student's Id Number: ");
                if(fall.checkStudent(test.Id)){
                    JOptionPane.showMessageDialog(frame, "This student is already in the system", "Error", JOptionPane.ERROR_MESSAGE);
                    continue;
                }
                
                String first = data.getWord("Enter student's first name: ");

                String last = data.getWord("Enter student's last name: ");

                test.name = new Name(first, last);

                String city = data.getWord("Enter the student's city: ");

                String street = data.getWord("Enter the student's street: ");

                String state = data.getWord("Enter the student's state: ");

                int zipcode = data.getInt("Enter the student's Zip Code: ");

                test.address = new Address(city, street, state, zipcode);

                

                fall.admissions.add(test);
                JOptionPane.showMessageDialog(frame, "Student Added", "Info", JOptionPane.PLAIN_MESSAGE);
            }

            if(s.equals("List Currently Registered Students")){
                
                JOptionPane.showMessageDialog(scrollpane, fall.showAdmissions(), "Currently Enrolled Students", JOptionPane.PLAIN_MESSAGE);
            }

            if(s.equals("List Dropped Students")){
                
                JOptionPane.showMessageDialog(scrollpane, fall.showDropped(), "Dropped Students", JOptionPane.PLAIN_MESSAGE);
            }

            if(s.equals("Remove a student from the database")){
                String id = data.getWord("Enter the student's ID: ");
                
                if(!(fall.checkStudent(id))){
                    JOptionPane.showMessageDialog(frame, "This student isn't in the system", "Error", JOptionPane.ERROR_MESSAGE);
                    continue;
                }
                
                fall.removeStudent(id);
                JOptionPane.showMessageDialog(frame, "Student Removed", "Info", JOptionPane.PLAIN_MESSAGE);
            }

            if(s.equals("Change a student's record")){
                String id = data.getWord("Enter the student's ID: ");
                
                if(!(fall.checkStudent(id))){
                    JOptionPane.showMessageDialog(frame, "This student isn't in the system", "Error", JOptionPane.ERROR_MESSAGE);
                    continue;
                }

                Object[] options2 = {"Add a course","Drop a course"};
                String t = (String)JOptionPane.showInputDialog(frame, "What would you like to do? ", "Change a student's record", JOptionPane.PLAIN_MESSAGE, null, options2, "Add a course");

                if(t.equals("Add a course")){
                    String course = data.getWord("Enter the course to add");
                    for(int x = 0; x < fall.admissions.size(); x++){
                        if(fall.admissions.get(x).Id.equals(id)){
                            fall.admissions.get(x).addCourse(course);
                            //System.out.print(course);
                        }
                    }
                    JOptionPane.showMessageDialog(frame, "Course Added", "Info", JOptionPane.PLAIN_MESSAGE);
                }

                if(t.equals("Drop a course")){
                    String course = data.getWord("Enter the course to drop");
                    for(int x = 0; x < fall.admissions.size(); x++){
                        if(fall.admissions.get(x).Id.equals(id)){
                            fall.admissions.get(x).dropCourse(course);
                        } 
                    }
                    JOptionPane.showMessageDialog(frame, "Course Removed", "Info", JOptionPane.PLAIN_MESSAGE);
                }
            }
        }while(!(s.equals("Exit"))); 
       
    System.exit(0);    
    
    
    }
    
    
    
 
    
}
