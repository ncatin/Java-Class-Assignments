
package assignment1;


public class Name extends Student {
    public String first;
    public String last;
    
    public Name(String first, String last){
        this.first = first;
        this.last = last;
    }
            
    public String getFirst(){
        return first;
    }
    
    public String getLast(){
        return last;
    }
    
    public void setFirst(String first){
        this.first = first;
    }
    
    public void setLast(String last){
        this.last = last;
    }
}
