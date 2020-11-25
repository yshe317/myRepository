import java.util.HashMap;
import java.util.Map;
public class HotelDatabase{  
    
    // room_number: guestsInARoom    
    Map<Integer,Integer> m; 
    static int totalGuests;        
    
    public HotelDatabase(){               
        totalGuests = 0;               
        m = new HashMap<Integer,Integer>();      
    }
    public void addGuestsToRoom(int room_number, int number_of_guests_to_add) {           
        if(m.get(room_number) == null){                      
            m.put(room_number,number_of_guests_to_add);                    
            totalGuests +=  number_of_guests_to_add;                                 
        }else{                     
            System.out.println("the room is occurpied");             
        }
    }
    public void removeGuestsFromRoom(int room_number) {               
        if(m.get(room_number) == null){                              
            System.out.println("the room is empty");             
        }else{                      
            totalGuests  -=  m.get(room_number);                      
            m.remove(room_number);                      
        }
    }
    public static int getTotal(){             
        return totalGuests;
    } 
     
}