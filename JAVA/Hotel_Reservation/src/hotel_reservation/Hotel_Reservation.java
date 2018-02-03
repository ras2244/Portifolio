/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hotel_reservation;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.mail.internet.AddressException;
import javax.mail.internet.InternetAddress;



/**
 *
 * @author Ricardo
 */
public class Hotel_Reservation {

    /**
     * @param args the command line arguments
     */
    
    public static String end = "done";
    public static boolean check;
    public static File file=null;
    static List<Single_Room> single=new ArrayList<>();
    static List<Double_Room> dual=new ArrayList<>();
    static List<Delux_Room> delux=new ArrayList<>();
    static List<Pent_House> pentHouse=new ArrayList<>();
    private static ServerSocket ss;    
    private final static int PORT = 3128;
    public static Thread mythread;
    
    public static void main(String[] args) {
       
        check=true;
        runFile(0);
        
        mythread = new Thread(new Server());
        mythread.run();
        mythread.start();
         
        //mainMenu();
    }
    
    
    

    public static boolean validateAddress(String address){
      return address.matches("\\d+\\s+([a-zA-Z]+|[a-zA-Z]+\\s[a-zA-Z]+)" );
   } 
    
    public static boolean validateName (String txt){
        String regx = "[A-Z][a-zA-Z]*";
        Pattern pattern = Pattern.compile(regx, Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(txt);
        return matcher.find();

    }
    
    public static boolean isValidTypeRoom(String Room){
        boolean result = true;
        String s="Single Room";
        String d="Double Room";
        String x="Delux Room";
        String p="Penthouse";
        if((Room.contains(s))||(Room.contains(d))||(Room.contains(x))||(Room.contains(p))){
            result=true;
        }
        else{
            result=false;
        }
        
        return result;
    }
    
    public static boolean isValidPhone(long phone){
        boolean result = true;
        String str=null;
        String regex = "^\\(?([0-9]{3})\\)?[-.\\s]?([0-9]{3})[-.\\s]?([0-9]{4})$";
        Pattern pattern = Pattern.compile(regex);
        try{
        str=String.valueOf(phone);
        Matcher m=pattern.matcher(str);
        if(!m.find()){
            result=false;
        }
        else{
            result=true;
        }
        }catch(NumberFormatException e){
          e.printStackTrace();
        }      
        
        return result;
    }    
    
    public static boolean isValidEmailAddress(String email) {
        boolean result = true;
        try {
          InternetAddress emailAddr = new InternetAddress(email);
          emailAddr.validate();
        } catch (AddressException ex) {
          result = false;
       }
       return result;
    }
    
    private static void runFile(int id){
        String s="Single Room";
        String d="Double Room";
        String x="Delux Room";
        String p="Penthouse";
        
        try{
        File file=new File("C:\\Users\\Ricardo\\Documents\\hotel.txt");
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        String line;
        if((line=br.readLine())==null&&id<100){
            for(int i=100; i<105;i++){
            Single_Room room=new Single_Room(i,70,s,true);
            single.add(room);
            }

            for(int i=200; i<205;i++){
            Double_Room room=new Double_Room(i,120,d,true);
            dual.add(room);
            }

            for(int i=300; i<304;i++){
            Delux_Room room=new Delux_Room(i,160,x,true);
            delux.add(room);
            }

            for(int i=400; i<402;i++){
            Pent_House room=new Pent_House(i,250,p,true);
            pentHouse.add(room);
            }
            createFile(single);
            createFile(dual);
            createFile(delux);
            createFile(pentHouse);
            check=false;
        }
        
        check=false;
        createFile(single);
        createFile(dual);
        createFile(delux);
        createFile(pentHouse);

        single.clear();
        dual.clear();
        delux.clear();
        pentHouse.clear();
        

        if(check==false){
            FileWriter writer = new FileWriter(file.getAbsoluteFile(),true);
            BufferedWriter bf = new BufferedWriter(writer);
            bf.write(end);
            bf.close();
            writer.close();
            check=true;
            }
        }
        
        
        catch (IOException e) {
    		System.out.println("Exception Occurred:");
	        e.printStackTrace();
	}
        
    }
    
    private static <T> void createFile(List<T> arrData)throws IOException{
                
        try {
            
	    file = new File("C:\\Users\\Ricardo\\Documents\\hotel.txt");
	    
            boolean fvar = file.createNewFile();
	    if (fvar){
	          System.out.println("File has been created successfully");
	    }

        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }     
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        //boolean check=false;
        String line="";
        int count=0;
        while((line=br.readLine())!=null){
            String[] words=line.split(",");
            for(String word: words){
                if(word.equals(end)){
                    check=true;
                    count++;
                }
            }
        }
        
 
        if(check==false){    
            FileWriter writer = new FileWriter(file.getAbsoluteFile(),true);
            BufferedWriter bf = new BufferedWriter(writer);

            int size = arrData.size();            
            for (int i=0;i<size;i++) {
                String str = arrData.get(i).toString();           
                bf.write(str);
                bf.newLine();
                //This prevent creating a blank like at the end of the file
                if(i < size-1)
                    bf.write("\n");
            }
            fr.close();
            br.close();
            bf.close();
            writer.close();
        }
    }
    
    public static List<String> SearchID(String id,File file){
        List<String> result=new ArrayList<>();
        //String path=file.getAbsolutePath();
        //Scanner scanner=new Scanner(path);
        try{
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);
            String line="";
            while((line=br.readLine())!=null){
                if(line.contains(id)){
                    String[] words = null;
                    //while(!line.isEmpty()){
                    words=line.split(",");                       
                    //}
                    if(words[0].contains(id)){
                        for(String word:words){
                            result.add(word);
                        }
                    break; 
                    }
                }
            }
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
        
        return result;
    }
    
    public static int RoomID(String choice){
        
        File file=new File("C:\\Users\\Ricardo\\Documents\\hotel.txt");
        String absolutePath = file.getAbsolutePath();        
        boolean check=false;
        boolean stop=false;
        boolean set=true;
        int id=0;
        int num=0;
        int count=0;
         try{
            Scanner scan=new Scanner(file);
            while(scan.hasNextLine()&&stop==false){
                String line = scan.nextLine();
                
                if(line.contains(choice)){
                String[] details = line.split(",");
                    String first=details[0];
                    String second=details[2];
                    id=Integer.valueOf(first);
                    while(details[2].contains("Single Room")){
                        String a,b,c,d;
                        a=details[0];
                        b=details[1];
                        c=details[2];
                        d=details[3];
                        
                        int val=Integer.valueOf(a);
                        double value=Double.valueOf(b);
                        boolean vacant=Boolean.valueOf(d);
                        Single_Room room=new Single_Room(val,value,c,vacant);
                        //List<Double_Room> copy = new ArrayList<Double_Room>();
                        single.add(room);
                        
                        int size=single.size();
                        if(set!=false){
                            while(count<size){
                                count++;
                                if(vacant!=false){
                                    single.get(size-1).setIsVacant(check);
                                    num=single.get(size-1).getRoom_Id();
                                    //dual.add(room);
                                    set=false;
                                    break;                                    
                                }
                                
                                
                            }
                        }
                        break;                               
                    }
                    
                    while(details[2].contains("Double Room")){
                        String a,b,c,d;
                        a=details[0];
                        b=details[1];
                        c=details[2];
                        d=details[3];
                        
                        int val=Integer.valueOf(a);
                        double value=Double.valueOf(b);
                        boolean vacant=Boolean.valueOf(d);
                        Double_Room room=new Double_Room(val,value,c,vacant);
                        //List<Double_Room> copy = new ArrayList<Double_Room>();
                        dual.add(room);
                        
                        int size=dual.size();
                        if(set!=false){
                            while(count<size){
                                count++;
                                if(vacant!=false){
                                    dual.get(size-1).setIsVacant(check);
                                    num=dual.get(size-1).getRoom_Id();
                                    //dual.add(room);
                                    set=false;
                                    break;                                    
                                }
                                
                                
                            }
                        }
                        break;
                    }
                    
                    if(details[2].contains("Delux Room")){
                        String a,b,c,d;
                        a=details[0];
                        b=details[1];
                        c=details[2];
                        d=details[3];
                        
                        int val=Integer.valueOf(a);
                        double value=Double.valueOf(b);
                        boolean vacant=Boolean.valueOf(d);
                        Delux_Room room=new Delux_Room(val,value,c,vacant);                        
                        delux.add(room);
                        
                        int size=delux.size();
                        if(set!=false){
                            while(count<size){
                                count++;
                                if(vacant!=false){
                                    delux.get(size-1).setIsVacant(check);
                                    num=delux.get(size-1).getRoom_Id();
                                    //dual.add(room);
                                    set=false;
                                    break;                                    
                                }
                                
                                
                            }
                        }
                        //break;                                             
                    }
                    if(details[2].contains("Penthouse")){
                        String a,b,c,d;
                        a=details[0];
                        b=details[1];
                        c=details[2];
                        d=details[3];
                        
                        int val=Integer.valueOf(a);
                        double value=Double.valueOf(b);
                        boolean vacant=Boolean.valueOf(d);
                        Pent_House room=new Pent_House(val,value,c,vacant);                        
                        pentHouse.add(room);
                        
                        int size=pentHouse.size();
                        if(set!=false){
                            while(count<size){
                                count++;
                                if(vacant!=false){
                                    pentHouse.get(size-1).setIsVacant(check);
                                    num=pentHouse.get(size-1).getRoom_Id();
                                    //dual.add(room);
                                    set=false;
                                    break;                                    
                                }
                                
                                
                            }
                        }
                        //break;                                                              
                    }
                    
                
                  //break;   
                }
                else{
                    
                    String[] details = line.split(",");
                    String first=details[0];
                    if(!"".equals(first)&&!"done".equals(first)){
                    
                        String second=details[2];
                        if(second!=choice){
                            String a,b,c,d;
                            a=details[0];
                            b=details[1];
                            c=details[2];
                            d=details[3];

                            int val=Integer.valueOf(a);
                            double value=Double.valueOf(b);
                            boolean vacant=Boolean.valueOf(d);
                            if(second.contains("Single Room")){
                                Single_Room room =new Single_Room(val,value,c,vacant);
                                single.add(room);
                            }
                            if(second.contains("Double Room")){
                                Double_Room room0 =new Double_Room(val,value,c,vacant);
                                dual.add(room0);
                            }
                            if(second.contains("Delux Room")){
                                Delux_Room room1 =new Delux_Room(val,value,c,vacant);
                                delux.add(room1);
                            }
                            if(second.contains("Penthouse")){
                                Pent_House room2 =new Pent_House(val,value,c,vacant);
                                pentHouse.add(room2);
                            }


                            //break;


                        }
                    }
                }
            
            }
            PrintWriter writer = new PrintWriter(file);
            writer.print("");
            writer.close();
            runFile(num);
            
            }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
            }catch(NumberFormatException e){
                e.printStackTrace();
            }
        
        return num;
    }
    
    public static void AvailableRooms(){
        
        File file=new File("C:\\Users\\Ricardo\\Documents\\hotel.txt");
        String absolutePath = file.getAbsolutePath();        
        boolean check=false;
        boolean stop=false;
        boolean set=true;
        int id=0;
        //int num=0;
        //int count=0;
         try{
            Scanner scan=new Scanner(file);
            while(scan.hasNextLine()){
                String line = scan.nextLine();
                String[] details = line.split(",");
                    String first=details[0];
                    if(!"".equals(first)&&!"done".equals(first)){
                    
                        String second=details[2];
                        
                            String a,b,c,d;
                            a=details[0];
                            b=details[1];
                            c=details[2];
                            d=details[3];

                            int val=Integer.valueOf(a);
                            double value=Double.valueOf(b);
                            boolean vacant=Boolean.valueOf(d);
                            if(second.contains("Single Room")){
                                Single_Room room =new Single_Room(val,value,c,vacant);
                                single.add(room);
                            }
                            if(second.contains("Double Room")){
                                Double_Room room0 =new Double_Room(val,value,c,vacant);
                                dual.add(room0);
                            }
                            if(second.contains("Delux Room")){
                                Delux_Room room1 =new Delux_Room(val,value,c,vacant);
                                delux.add(room1);
                            }
                            if(second.contains("Penthouse")){
                                Pent_House room2 =new Pent_House(val,value,c,vacant);
                                pentHouse.add(room2);
                            }


                            //break;


                       // }
                    }
            }
            
         }catch(FileNotFoundException e){
             e.printStackTrace();
         }
    }

    public static void BookRoom()throws IOException{
        
        int numOfGuests;
        String s="Single Room";
        String d="Double Room";
        String x="Delux Room";
        String p="Penthouse";
        AvailableRooms();
        System.out.print("No of guests:");
        Scanner input=new Scanner(System.in);
        
        numOfGuests=input.nextInt();
        
        if(numOfGuests<=2){
              int count=0;

            for(int j=0;j<single.size();j++){               
                if(single.get(j).getIsVacant()){
                    count++;                   
                }
            }
            System.out.println("No of Available rooms: "+count);
            System.out.println("Room ID"+"\t\t"+"Room Type");
            for(int i=0;i<single.size();i++){               
                if(single.get(i).getIsVacant()){                                       
                    System.out.println(single.get(i).getRoom_Id()+"\t\t"+single.get(i).getRoom_Type());
                    
                }
            }
            System.out.println();
        }
        
        if(numOfGuests>2&&numOfGuests<4){
            int count=0;
            
            for(int j=0;j<single.size();j++){               
                if(single.get(j).getIsVacant()){
                    count++;                   
                }
            }
            
            for(int j=0;j<dual.size();j++){               
                if(dual.get(j).getIsVacant()){
                    count++;                   
                }
            }
            
//            for(int j=0;j<delux.size();j++){               
//                if(delux.get(j).getIsVacant()){
//                    count++;                   
//                }
//            }
//            for(int j=0;j<pentHouse.size();j++){               
//                if(pentHouse.get(j).getIsVacant()){
//                    count++;                   
//                }
//            }
            
            System.out.println("No of Available rooms: "+count);
            System.out.println("Room ID"+"\t\t"+"Room Type");
            for(int i=0;i<single.size();i++){               
                if(single.get(i).getIsVacant()){
                    System.out.println(single.get(i).getRoom_Id()+"\t\t"+single.get(i).getRoom_Type());
                }                
            }
            for(int i=0;i<dual.size();i++){
                if(dual.get(i).getIsVacant()){
                    System.out.println(dual.get(i).getRoom_Id()+"\t\t"+dual.get(i).getRoom_Type());
                }                 
            }
//            for(int i=0;i<delux.size();i++){
//                if(delux.get(i).getIsVacant()){
//                    System.out.println(delux.get(i).getRoom_Id()+"\t\t"+delux.get(i).getRoom_Type());
//                }                 
//            }
//
//            for(int i=0;i<pentHouse.size();i++){
//                if(pentHouse.get(i).getIsVacant()){
//                    System.out.println(pentHouse.get(i).getRoom_Id()+"\t\t"+pentHouse.get(i).getRoom_Type());
//                }                 
//            }
        }
            
        if(numOfGuests >=4){
            int count=0;
            for(int j=0;j<single.size();j++){               
                if(single.get(j).getIsVacant()){
                    count++;                   
                }
            }            
            for(int j=0;j<dual.size();j++){               
                if(dual.get(j).getIsVacant()){
                    count++;                   
                }
            }            
            for(int j=0;j<delux.size();j++){               
                if(delux.get(j).getIsVacant()){
                    count++;                   
                }
            }            
            for(int j=0;j<pentHouse.size();j++){               
                if(pentHouse.get(j).getIsVacant()){
                    count++;                   
                }
            }
            System.out.println("No of Available rooms: "+count);
            System.out.println("Room ID"+"\t\t"+"Room Type");
            for(int i=0;i<single.size();i++){               
                if(single.get(i).getIsVacant()){
                    System.out.println(single.get(i).getRoom_Id()+"\t\t"+single.get(i).getRoom_Type());
                }
            }
            for(int c=0;c<dual.size();c++){
                if(dual.get(c).getIsVacant()){
                    System.out.println(dual.get(c).getRoom_Id()+"\t\t"+dual.get(c).getRoom_Type());
                }                 
            }
            for(int j=0;j<delux.size();j++){ 
                if(delux.get(j).getIsVacant()){
                    System.out.println(delux.get(j).getRoom_Id()+"\t\t"+delux.get(j).getRoom_Type());
                }
            }
            for(int z=0;z<pentHouse.size();z++){ 
                if(pentHouse.get(z).getIsVacant()){
                    System.out.println(pentHouse.get(z).getRoom_Id()+"\t\t"+pentHouse.get(z).getRoom_Type());
                }
            }
        }
        if(numOfGuests<=2){
            boolean isValid=true;
            Scanner scan=new Scanner(System.in);
            System.out.print("Choose the room type(Insert exactly like it shows):");
            String roomType= scan.nextLine();
            isValid=isValidTypeRoom(roomType);
            while(!isValid){
                input.reset();
                System.out.println("Insert room type Again: Eg:Single Room");
                System.out.print("Room Type:");
                roomType=input.nextLine();
                isValid=isValidTypeRoom(roomType);
                if(isValid){
                    input.nextLine();
                }
            }      
            single.clear();
            dual.clear();
            delux.clear();
            pentHouse.clear();
            int roomId=RoomID(roomType);
            AvailableRooms();
            System.out.print("No of days to be booked for:");
            int numOfdays= input.nextInt();        
            if(roomType.contains(s)){
                double rate=single.get(1).getRate();
                //double rates=Double.parseDouble(rate);
                System.out.println("The Rate offered for Single Room is $"+rate);
                System.out.println("The Rate for "+numOfdays+" day(s) is $"+(rate*numOfdays));
                System.out.println();
                List<Guest> filledGuest=new ArrayList<>();
                filledGuest=GuestForm();
                ReserveRoom(filledGuest,numOfGuests,numOfdays,roomType,roomId);
            }
            
        }
        else if(numOfGuests>2&&numOfGuests<4){
            System.out.println("How many room(s)1 or 2");
            int numOfrooms= input.nextInt(); 
            //Scanner scan=new Scanner(System.in);
            //System.out.print("");
            String roomType= d;
            single.clear();
            dual.clear();
            delux.clear();
            pentHouse.clear();
            int roomId=RoomID(roomType);
            AvailableRooms();
            System.out.print("No of days to be booked for:");
            int numOfdays= input.nextInt();            
            double rate=dual.get(1).getRate();                
            System.out.println("The Rate offered for Single Room is $"+rate);
            System.out.println("The Rate for "+numOfdays+" day(s) is $"+(rate*numOfdays));
            System.out.println();
            List<Guest> filledGuest=new ArrayList<>();
            filledGuest=GuestForm();
            ReserveRoom(filledGuest,numOfGuests,numOfdays,roomType,roomId);
            if(numOfrooms==2){
                double rate2=single.get(1).getRate();                
                System.out.println("The Rate offered for Single Room is $"+rate2);
                System.out.println("The Rate for "+numOfdays+" day(s) is $"+(rate2*numOfdays));
                System.out.println();
                single.clear();
                dual.clear();
                delux.clear();
                pentHouse.clear();
                int roomId2=RoomID(roomType);
                roomType=s;
                numOfGuests=1;
                Scanner scan=new Scanner(System.in);
                System.out.print("If New form for another Guest type 1:");
                int formguest=scan.nextInt();
                if(formguest==1){
                    List<Guest> filledGuest2=new ArrayList<>();
                    filledGuest2=GuestForm();
                    ReserveRoom(filledGuest2,numOfGuests,numOfdays,roomType,roomId2);
                }else{
                    ReserveRoom(filledGuest,numOfGuests,numOfdays,roomType,roomId2);
                }
            }
            
        }else{
            int count=0;
            System.out.println("How many room(s):");
            int numOfrooms= input.nextInt();
            do{
                boolean isValid=true;
                Scanner scan=new Scanner(System.in);
                System.out.print("Choose the room type(Insert exactly like it shows):");
                String roomType= scan.nextLine();
                isValid=isValidTypeRoom(roomType);
                while(!isValid){
                    input.reset();
                    System.out.println("Insert room type Again: Eg:Single Room");
                    System.out.print("Room Type:");
                    roomType=scan.nextLine();
                    isValid=isValidTypeRoom(roomType);
//                    if(isValid){
//                        scan.nextLine();
//                    }
                }      
                single.clear();
                dual.clear();
                delux.clear();
                pentHouse.clear();
                int roomId=RoomID(roomType);
                AvailableRooms();
                System.out.print("No of days to be booked for:");
                int numOfdays= input.nextInt();
                if(roomType.contains(s)){
                    double rate=single.get(1).getRate();
                    //double rates=Double.parseDouble(rate);
                    System.out.println("The Rate offered for Single Room is $"+rate);
                    System.out.println("The Rate for "+numOfdays+" day(s) is $"+(rate*numOfdays));
                    System.out.println();
                    List<Guest> filledGuest=new ArrayList<>();
                    filledGuest=GuestForm();
                    ReserveRoom(filledGuest,numOfGuests,numOfdays,roomType,roomId);
                    single.clear();
                    dual.clear();
                    delux.clear();
                    pentHouse.clear();
                }
                if(roomType.contains(d)){
                    double rate=dual.get(1).getRate();
                    //double rates=Double.parseDouble(rate);
                    System.out.println("The Rate offered for Single Room is $"+rate);
                    System.out.println("The Rate for "+numOfdays+" day(s) is $"+(rate*numOfdays));
                    System.out.println();
                    List<Guest> filledGuest=new ArrayList<>();
                    filledGuest=GuestForm();
                    ReserveRoom(filledGuest,numOfGuests,numOfdays,roomType,roomId);
                    single.clear();
                    dual.clear();
                    delux.clear();
                    pentHouse.clear();
                }
                if(roomType.contains(x)){
                    double rate=delux.get(1).getRate();
                    //double rates=Double.parseDouble(rate);
                    System.out.println("The Rate offered for Single Room is $"+rate);
                    System.out.println("The Rate for "+numOfdays+" day(s) is $"+(rate*numOfdays));
                    System.out.println();
                    List<Guest> filledGuest=new ArrayList<>();
                    filledGuest=GuestForm();
                    ReserveRoom(filledGuest,numOfGuests,numOfdays,roomType,roomId);
                    single.clear();
                    dual.clear();
                    delux.clear();
                    pentHouse.clear();
                }
                if(roomType.contains(p)){
                    double rate=pentHouse.get(1).getRate();
                    //double rates=Double.parseDouble(rate);
                    System.out.println("The Rate offered for Single Room is $"+rate);
                    System.out.println("The Rate for "+numOfdays+" day(s) is $"+(rate*numOfdays));
                    System.out.println();
                    List<Guest> filledGuest=new ArrayList<>();
                    filledGuest=GuestForm();
                    ReserveRoom(filledGuest,numOfGuests,numOfdays,roomType,roomId);
                    single.clear();
                    dual.clear();
                    delux.clear();
                    pentHouse.clear();
                }
             
            count++;    
            }while(numOfrooms!=count);
            
        }
        
       
    }
    
    public static void ReserveRoom(List<Guest> g,int numOfGuests,int numOfdays, String roomtype,int rid){
        int count=0;
        Scanner input=new Scanner(System.in);
        DateFormat format = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm");
        System.out.println("Enter date and time in the format yyyy-MM-ddTHH:mm");
        //System.out.println("For example, it is now " + format.format(new Date()));
        Date check_in = null;
        while (check_in == null) {
            String line = input.nextLine();
            try {
                check_in = format.parse(line);
            } catch (ParseException e) {
                System.out.println("Sorry, that's not valid. Please try again.");
            }
        }
        
        Date currentDate = new Date();
         
        Calendar c = Calendar.getInstance();
        c.setTime(check_in);
        c.add(Calendar.DATE, numOfdays);       
        Date check_out = c.getTime();
        try {
            
	    file = new File("C:\\Users\\Ricardo\\Documents\\BookID.txt");
	     
            boolean fvar = file.createNewFile();
	    if (fvar){
	          System.out.println("File has been created successfully");
	    }
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
        
        try{
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        FileWriter writer = new FileWriter(file.getAbsoluteFile(),true);
        BufferedWriter bf = new BufferedWriter(writer);
        //boolean check=false;
        String line,lastline="";
        
        int parseId=0;
        String parseback;
        if((line=br.readLine())==null){
            count++;
            bf.write(count);
            bf.newLine();
        }
        else{
            while ((line = br.readLine()) != null){
                lastline = line;
            }
            try{
            parseId=Integer.valueOf(lastline);
            }catch(NumberFormatException e){
                e.printStackTrace();
            }
            count=parseId+1;
            try{
            parseback=String.valueOf(count);
            bf.newLine();
            bf.write(parseback);
            }catch(NumberFormatException e){
                e.printStackTrace();
            }         
        }
        fr.close();
        br.close();
        bf.close();
        writer.close();
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
        
        
        List<Reservation> newBook= new ArrayList<>();
        Reservation reserv=new Reservation(currentDate,check_in,check_out,numOfGuests,roomtype,g,rid);
        reserv.setBook_Id(count);
        newBook.add(reserv);
        
        try {
            
	    file = new File("C:\\Users\\Ricardo\\Documents\\Reservation.txt");
	     
            boolean fvar = file.createNewFile();
	    if (fvar){
	          System.out.println("File has been created successfully");
	    }
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
        
        try{
            FileWriter writer = new FileWriter(file.getAbsoluteFile(),true);
            BufferedWriter bf = new BufferedWriter(writer);
            int size = newBook.size();            
            for (int i=0;i<size;i++) {
                String str = newBook.get(i).toString();           
                bf.write(str);
                bf.newLine();
                //This prevent creating a blank like at the end of the file
                if(i < size-1)
                    bf.write("\n");
            }
            
            bf.close();
            writer.close();
            
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
        
        
    }
        
    public static List<Guest> GuestForm(){
        String title=" ";
        String fname=" ";
        String lname=" ";
        String addr=" ";
        long phn=0L;
        String email=" ";
        int count=0;
        boolean isValid;

        System.out.println("Hotel Reservation System - Guest form");
        Scanner input=new Scanner(System.in);
        Scanner input2=new Scanner(System.in);
        System.out.print("Title:");        
        title=input.next();
        input.nextLine();
        System.out.print("First Name:");
        fname=input.next();
        isValid=validateName(fname);
        while(!isValid){
            input.reset();
            System.out.println("Insert a valid name: Eg:John");
            System.out.print("First Name:");
            fname=input.next();
            isValid= validateName(fname);
//            if(isValid){
//                input.nextLine();
//            }
        }        
        System.out.print("Last Name:");
        lname=input.next();
        isValid=validateName(lname);
        while(!isValid){
            input.reset();
            System.out.println("Insert a valid name: Eg:Lenon");
            System.out.print("Last Name:");
            lname=input.next();
            isValid= validateName(lname);
//            if(isValid){
//                input.nextLine();
//            }
        }
        input.reset();
        System.out.print("Address:");
        addr=input.nextLine();
        isValid=validateAddress(addr);
        while(!isValid){
            input.reset();
            System.out.println("Insert a valid Address: Eg:123 Street..");
            System.out.print("Address:");
            addr=input.nextLine();
            isValid=validateAddress(addr);
//            if(isValid){
//                input.nextLine();
//            }
        }       
        //input.nextLine();
        System.out.print("Phone:");        
        phn=input2.nextLong();
        isValid=isValidPhone(phn);
        while(!isValid){
            input2.reset();
            System.out.println("Insert a valid phone: 9999999999");
            System.out.print("Phone:");
            phn=input2.nextLong();
            isValid=isValidPhone(phn);
        }        
        System.out.print("Email:");
        email=input.next();
        isValid= isValidEmailAddress(email);
        while(!isValid){
            input.reset();
            System.out.println("Insert a valid Email: abc@abc.xx");
            System.out.print("Email:");
            email=input.next();
            isValid= isValidEmailAddress(email);
//            if(isValid){
//                input.nextLine();
//            }
        }
        try {
            
	    file = new File("C:\\Users\\Ricardo\\Documents\\GuestID.txt");
	     
            boolean fvar = file.createNewFile();
	    if (fvar){
	          System.out.println("File has been created successfully");
	    }
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
        
        try{
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        FileWriter writer = new FileWriter(file.getAbsoluteFile(),true);
        BufferedWriter bf = new BufferedWriter(writer);
        //boolean check=false;
        String line,lastline="";
        
        int parseId=0;
        String parseback;
        if((line=br.readLine())==null){
            count++;
            bf.write(count);
            bf.newLine();
        }
        else{
            while ((line = br.readLine()) != null){
                lastline = line;
            }
            try{
            parseId=Integer.valueOf(lastline);
            }catch(NumberFormatException e){
                e.printStackTrace();
            }
            count=parseId+1;
            try{
            parseback=String.valueOf(count);
            bf.newLine();
            bf.write(parseback);
        }catch(NumberFormatException e){
            e.printStackTrace();
        }
       
        }
        fr.close();
        br.close();
        bf.close();
        writer.close();
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
        
        List<Guest> guest=new ArrayList<>();       
        Guest newGuest=new Guest(title,fname,lname,addr,phn,email);
        newGuest.setGuest_ID(count);
        guest.add(newGuest);
        
        try {
            
	    file = new File("C:\\Users\\Ricardo\\Documents\\Guest.txt");
	     
            boolean fvar = file.createNewFile();
	    if (fvar){
	          System.out.println("File has been created successfully");
	    }
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
        
        try{
            FileWriter writer = new FileWriter(file.getAbsoluteFile(),true);
            BufferedWriter bf = new BufferedWriter(writer);
            int size = guest.size();            
            for (int i=0;i<size;i++) {
                String str = guest.get(i).toString();           
                bf.write(str);
                bf.newLine();
                //This prevent creating a blank like at the end of the file
                if(i < size-1)
                    bf.write("\n");
            }
            
            bf.close();
            writer.close();
            
        }catch (IOException e) {
                System.out.println("Exception Occurred:");
                e.printStackTrace();
        }
       return guest;
    }
    
    public static void mainMenu(){
        
        
        Scanner input = new Scanner(System.in);
        int option=0;
        do{            
            
            System.out.println(" \nHOTEL RESERVATION SYSTEM: MAIN MENU");
            System.out.println("=====================================");
            System.out.println("[1] BOOK A ROOM");
            System.out.println("[2] BILL SERVICE");
            System.out.println("[3] CURRRENT BOOKINGS");
            System.out.println("[4] AVAILABLE ROOMS");
            System.out.println("[5] EXIT");
            
            
            System.out.print("Please Choose an Option:");
            option=input.nextInt();
            System.out.println();
            
            switch(option){
                case 1:
                {
                    
                    //System.out.println("\nThank you!\n");
                    //option=5;
                    try{
                    BookRoom();
                    }catch (IOException e) {
                        System.out.println("Exception Occurred:");
                        e.printStackTrace();
                    }     
                    break;
                }
                
                case 2:
                {
                    //bill service method
                    String s="Single Room";
                    String d="Double Room";
                    String x="Delux Room";
                    String p="Penthouse";
                    AvailableRooms();
                    Scanner scan=new Scanner(System.in);                    
                    System.out.println("Enter Booking ID");
                    String id=scan.next();
                    File file=new File("C:\\Users\\Ricardo\\Documents\\Reservation.txt");
                    List<String> Booking=new ArrayList<>();
                    Booking=SearchID(id,file);
//                    for(String res:Booking){
//                        System.out.print(res+", ");
//                    }
                    
                    System.out.println("Booking ID: "+Booking.get(0));
                    System.out.println("Guest Name: "+Booking.get(4));
                    System.out.println("Number of days: "+Booking.get(5));
                    double days=0;
                    try{
                        days=Double.parseDouble(Booking.get(5));
                    }catch(NumberFormatException e){
                         e.printStackTrace();
                    }         
                    System.out.println("Type of Room: "+Booking.get(6));
                    String room= Booking.get(6);
                    double rate=0;
                    if(room.contains(s)){
                        System.out.println("Rate per night: "+single.get(0).getRate());
                        rate=(single.get(0).getRate());
                    }
                    if(room.contains(d)){
                        System.out.println("Rate per night: "+dual.get(0).getRate());
                        rate=(dual.get(0).getRate());
                    }
                    if(room.contains(x)){
                        System.out.println("Rate per night: "+delux.get(0).getRate());
                        rate=(delux.get(0).getRate());
                    }
                    if(room.contains(p)){
                        System.out.println("Rate per night: "+pentHouse.get(0).getRate());
                        rate=(pentHouse.get(0).getRate());
                    }
                    
                    Scanner input2=new Scanner(System.in);
                    System.out.print("Discont: ");
                    double discont=input2.nextDouble();                    
                    while(!(discont==5 ||discont==10||discont==15||discont==20||discont==25 )){
                        input2.reset();                        
                        System.out.println("Please enter 5, 10 , 15, 20 or 25 as discount");
                        discont=input2.nextDouble();
                        
                    }
                    discont=discont/100;
                    double Amount=0;
                    
                    if(discont!=0){
                        double value=0;
                        value=(rate*days)*discont;
                        Amount=(rate*days)-value;
                        System.out.println("Amount: $"+Amount);
                    }
                    else{
                        Amount=rate*days;
                        System.out.println("Amount: $"+Amount);
                        }
                    Bill bill = new Bill(Amount,Booking.get(4),Booking.get(0),Booking.get(7));
                    System.out.print(bill.toString());
                    single.clear();
                    dual.clear();
                    delux.clear();
                    pentHouse.clear();
                    break;
                }
                case 3:
                {
                    
                    File file=new File("C:\\Users\\Ricardo\\Documents\\Reservation.txt");
                    String absolutePath = file.getAbsolutePath();
                    List<Reservation> ListOfBooking=new ArrayList<Reservation>();
                    int lineIndex=0;
                    try{
                    Scanner scan=new Scanner(file);
                    while(scan.hasNextLine()){
                        String line = scan.nextLine();
                        String[] details = line.split(",");
                        String first=details[0];
                        if(!"".equals(first)&&!"done".equals(first)){
                            lineIndex++;

                            String second=details[1];
                            String thrird=details[2];
                            String forth=details[3];
                            String fifth=details[4];;
                            String sixth=details[5];
                            String seventh=details[6];
                            String eighth=details[7];

                            int id=Integer.valueOf(first);
                            DateFormat format = new SimpleDateFormat("EEE MMM d HH:mm:ss zzz yyyy");
                            Date cur=format.parse(second);
                            Date ch_in=format.parse(thrird);
                            Date ch_out=format.parse(forth);
                            int num=Integer.valueOf(sixth);
                            int num2=Integer.valueOf(eighth);

                            Reservation copy = new Reservation(cur,ch_in,ch_out,num,seventh,fifth,num2);
                            copy.setBook_Id(id);
                            ListOfBooking.add(copy);
                        }
                    }
                    }catch (IOException e) {
                        System.out.println("Exception Occurred:");
                        e.printStackTrace();
                    }catch(NumberFormatException e){
                        e.printStackTrace();
                    }catch(ParseException e){
                        e.printStackTrace();
                    }
                    
                    System.out.println("No of current bookings are: "+lineIndex);
                    System.out.println("Booking #\t\tCustomer Name\t\tRoom Type\t\tRoom No\t\tNo of Days");
                    for(int i=0;i<lineIndex;i++){
                        System.out.print(ListOfBooking.get(i).getBook_Id()+"\t\t\t"+ListOfBooking.get(i).getGuest()+"\t\t\t"+ListOfBooking.get(i).getRoomtype()
                                +"\t\t"+ListOfBooking.get(i).getRoom_Id()+"\t\t"+ListOfBooking.get(i).getNumOfGuests()+"\n");
                    }
                    break;
                }
                case 4:
                {
                    
                    single.clear();
                    dual.clear();
                    delux.clear();
                    pentHouse.clear();
                    AvailableRooms();
                    int count=0;
                    for(int j=0;j<single.size();j++){               
                        if(single.get(j).getIsVacant()){
                            count++;                   
                        }
                    }
            
                    for(int j=0;j<dual.size();j++){               
                        if(dual.get(j).getIsVacant()){
                            count++;                   
                        }
                    }
                    
                    for(int j=0;j<delux.size();j++){               
                        if(delux.get(j).getIsVacant()){
                            count++;                   
                        }
                    }
                    for(int j=0;j<pentHouse.size();j++){               
                        if(pentHouse.get(j).getIsVacant()){
                            count++;                   
                        }
                    }
            
                    System.out.println("No of Available rooms: "+count);
                    System.out.println("Room ID"+"\t\t"+"Room Type");
                    for(int i=0;i<single.size();i++){               
                        if(single.get(i).getIsVacant()){
                            System.out.println(single.get(i).getRoom_Id()+"\t\t"+single.get(i).getRoom_Type());
                        }                
                    }
                    for(int i=0;i<dual.size();i++){
                        if(dual.get(i).getIsVacant()){
                            System.out.println(dual.get(i).getRoom_Id()+"\t\t"+dual.get(i).getRoom_Type());
                        }                 
                    }

                    for(int i=0;i<delux.size();i++){
                        if(delux.get(i).getIsVacant()){
                            System.out.println(delux.get(i).getRoom_Id()+"\t\t"+delux.get(i).getRoom_Type());
                        }                 
                    }

                    for(int i=0;i<pentHouse.size();i++){
                        if(pentHouse.get(i).getIsVacant()){
                            System.out.println(pentHouse.get(i).getRoom_Id()+"\t\t"+pentHouse.get(i).getRoom_Type());
                        }                 
                    }
                    single.clear();
                    dual.clear();
                    delux.clear();
                    pentHouse.clear();
                    
                    
                    break;
                }
                case 5:
                {
                    mythread.stop();                    
                    System.out.println("\nThank you!\n");
                    break;
                }
            }
            
        }while(option!=5);
        
        System.out.println();
    }
    
}

