
package assignment1;

public class Address {
    String city;
    String street;
    String state;
    int zipcode;
    
    public Address(String city, String street, String state, int zipcode){
        this.city = city;
        this.street = street;
        this.state = state;
        this.zipcode = zipcode;
        
    }
    
    public String getCity(){
        return city;
    }
    
    public String getStreet(){
        return street;
    }
    
    public String getState(){
        return state;
    }
    
    public int getZip(){
        return zipcode;
    }
    
    public void setCity(String city){
        this.city = city;
    }
    
    public void setStreet(String street){
        this.street = street;
    }
    
    public void setState(String state){
        this.state = state;
    }
    
    public void setZip(int zipcode){
        this.zipcode = zipcode;
    }
}
