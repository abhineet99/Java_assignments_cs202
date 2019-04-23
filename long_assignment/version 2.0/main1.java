//import java.awt.SystemTray;
import java.util.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.*;
class productAtSamePathException extends Exception{
    private static final long serialVersionUID = 1L;

    // constructor
    productAtSamePathException(){
        super("The product is already present! You may have wanted to use modify functionality.");
    }
}
class InvalidDeletePathException extends Exception{
    private static final long serialVersionUID = 1L;

    // constructor
    InvalidDeletePathException(){
        super("Invalid Path");
    }
}
class OutOfStockException extends Exception{
    private static final long serialVersionUID = 1L;

    // constructor
    OutOfStockException(){
        super("The requested product is out of stock!");
    }
    int returnRemainingFunds(int remainingFunds){
        return remainingFunds;
    }
}
class FundsNotSufficient extends Exception{
    private static final long serialVersionUID = 1L;

    FundsNotSufficient(int funds) {
        super("Funds aren't sufficient for this transaction, you need to pay" + funds);
    }
    int returnRemainingFunds(int remainingFunds){
        return remainingFunds;
    }
}
class product{
    //String category;
    private String subcategory;
    private String productName;
    private int price;
    private int units;
    public product(String subcategory,String productName,int price,int units){
        //this.category=category;
        this.subcategory=subcategory;
        this.productName=productName;
        this.price=price;
        this.units=units;
    } 
    public String getSubcategory(){
        return this.subcategory;
    }
    public String getProductName(){
        return this.productName;
    }
    public int getUnits(){
        return this.units;
    }
    public int getPrice(){
        return this.price;
    }
    public void product_modify(int price,int units){
        this.price=price;
        this.units=units;
    }
    public void product_modify_price(int price){
        this.price=price;
    }
    public void product_modify_units(int units){
        this.units=units;
    }
}
class database{
    //product[] prod_collection=new product[25];
    //List<product> product_list; //=new ArrayList<product>();
    Map<String, List<product>> databaseMap;// = new HashMap<>();
    private int revenue;

    public database(){
        revenue=0;
        databaseMap = new HashMap<String, List<product>>();;
//product_list=new ArrayList<product>();
    }
    public int getRevenue(){
        return revenue;
    }
    public void insert(product productToBeAdded){
        String subcategory=productToBeAdded.getSubcategory();
        try{
            if(databaseMap.containsKey(subcategory)){
                int flag=0;
                List<product> productListInThatCategory=databaseMap.get(subcategory);
                for(int i=0;i<productListInThatCategory.size();i++){
                    if(productListInThatCategory.get(i).getProductName().equals(productToBeAdded.getProductName())){
                        flag=1;
                        throw new productAtSamePathException();
                        //System.out.println("Product being entered already exists, you may want to use modify functionality");
                        //break;
                    }
                    
                }
                if(flag==0)
                productListInThatCategory.add(productToBeAdded);
            }
            else{
                List<product> productList =new ArrayList<product>();
                productList.add(productToBeAdded);
                databaseMap.put(subcategory, productList);
                //System.out.println("Done!");
                //intScanner.close();
            }
        }
        catch(Exception e){
            System.out.println(e.toString()+e.getMessage());
        }

    }
    public void insert(String subcategory,String productName){
        if(databaseMap.containsKey(subcategory)){
            List<product> productListInThatCategory=databaseMap.get(subcategory);
            int flag=0;
            try{
                for (int i = 0; i < productListInThatCategory.size(); i++) {
                    if(productName.equals((productListInThatCategory.get(i)).getProductName())){
                    // System.out.println("Error: The product is already present! You may have wanted to use modify functionality.");
                        flag=1;
                        throw new productAtSamePathException();
                    
                    }

                }
            }
            catch(productAtSamePathException ex){
                System.out.println(ex.toString()+ex.getMessage());
            }
            if(flag!=1){
                System.out.println("Seems like it is a new product! Please enter the price and units to enter the product into database");
                Scanner intScanner=new Scanner(System.in);
                int price=intScanner.nextInt();
                int units=intScanner.nextInt();
                product productToBeAdded=new product(subcategory, productName, price, units);
                productListInThatCategory.add(productToBeAdded);
                databaseMap.put(subcategory,productListInThatCategory);
                System.out.println("Done!");
                //intScanner.close();

            }
            
        }
        else{
            List<product> productList =new ArrayList<product>();
            System.out.println("Seems like it is a new product and a subcategory! Please enter the price and units to enter the product into database");
            Scanner intScanner=new Scanner(System.in);
            int price=intScanner.nextInt();
            int units=intScanner.nextInt();
            product productToBeAdded=new product(subcategory, productName, price, units);
            productList.add(productToBeAdded);
            databaseMap.put(subcategory, productList);
            System.out.println("Done!");
            //intScanner.close();
        }
    }
    public void delete(String subcategory){
        //int inputLength=subcategory.length();
        int greaterThanCount=0;
        for(int i=0;i<subcategory.length();i++){
            if(subcategory.charAt(i)=='>'){
                greaterThanCount=greaterThanCount+1;

            }
        }

        try{
        //it is a product case
            if(greaterThanCount==2){
                String[] parts = subcategory.split(">");
                String category = parts[0]; //category
                subcategory = parts[1]; //subcategory
                String productName=parts[2];
                subcategory=category+">"+subcategory;
                
                    if(databaseMap.containsKey(subcategory)){
                        List<product> productListInThatCategory=databaseMap.get(subcategory);
                        int flag=0;
                        for (int i = 0; i < productListInThatCategory.size(); i++) {
                            if(productName.equals((productListInThatCategory.get(i)).getProductName())){
                                productListInThatCategory.remove(i);
                                System.out.println("The product has been removed!");
                                flag=1;
                                break;
                            }
                        databaseMap.put(subcategory,productListInThatCategory);    
            
                        }
                        if(flag!=1){
                            throw new InvalidDeletePathException();
            
                        }
                        
                    }
                    else{
                        throw new InvalidDeletePathException();
                        //System.out.println("Invalid path!");
                    }
                




            }
            // when it is a subcategory
            else if(greaterThanCount==1){


                if (databaseMap.containsKey(subcategory)){
                    databaseMap.remove(subcategory);
                    System.out.println("The product has been removed!");
                }
                else{
                    throw new InvalidDeletePathException();
                    //System.out.println("Invalid path!");
                }

            }
            else{
                throw new InvalidDeletePathException();
            }
        }
        catch(Exception e){
            System.out.println(e.toString());
        }
    }
    public product search(String productName){
        Iterator<Map.Entry<String, List<product>>> it= databaseMap.entrySet().iterator();
        //int flag=0;
        while (it.hasNext()) {
            Map.Entry<String, List<product>> pair = (Map.Entry<String, List<product>>)it.next();
            List<product> productList =pair.getValue();
            for (int i = 0; i < productList.size(); i++) {
                if(productName.equals((productList.get(i)).getProductName())){
                    return productList.get(i);
                }
            //it.remove(); // avoids a ConcurrentModificationException
            }
        }
        System.out.println("Product not found, returning a false reference!");
        return new product("false","false",-1,-1);




    }
    public void modify(String productName){
        product productToBeModified=search(productName);
        if((productToBeModified.getProductName()).equals("false")){
            System.out.println("The product ain't there in the database!");
        }
        else{
            System.out.println("Enter the new price and units, enter '-1' if you don't want the attribute to be changed");
            Scanner intScanner=new Scanner(System.in);
            int price1=intScanner.nextInt();
            int units1=intScanner.nextInt();
            
            if(price1!=-1){
                productToBeModified.product_modify_price(price1);
            }
            if(units1!=-1){
                productToBeModified.product_modify_units(units1);
            }
            //intScanner.close();
        }
    }
    public int sale(product productToBeBought,int quantityDemanded,int remainingFundsWithCustomer){
        int unitsAvailable=productToBeBought.getUnits();
        int priceToBePaid=quantityDemanded*productToBeBought.getPrice();
        try{
            if(unitsAvailable<quantityDemanded){
                //System.out.println("The number of units demanded aren't available, concerned product is: "+ productToBeBought.getProductName());
                //return remainingFundsWithCustomer;
                throw new OutOfStockException();
            }
            
            
            if(priceToBePaid>remainingFundsWithCustomer){
                throw new FundsNotSufficient(priceToBePaid);
                //System.out.println("Funds aren't sufficient for this transaction!,concerned product is: "+ productToBeBought.getProductName() + "\nYou need to pay" +priceToBePaid);
                //return remainingFundsWithCustomer;
            }
        }
        catch(OutOfStockException e){
            System.out.println(e.toString()+e.getMessage() );
            return e.returnRemainingFunds(remainingFundsWithCustomer);
        }
        catch(FundsNotSufficient e){
            System.out.print(e.toString()+e.getMessage());
            return e.returnRemainingFunds(remainingFundsWithCustomer);
        }
        productToBeBought.product_modify_units(productToBeBought.getUnits()-quantityDemanded);
        System.out.println("Transaction successful of product: "+productToBeBought.getProductName());
        revenue+=priceToBePaid;
        return remainingFundsWithCustomer-priceToBePaid;

    }

}
class Pair<L,R> {
    private L l;
    private R r;
    public Pair(L l, R r){
        this.l = l;
        this.r = r;
    }
    public L getL(){ return l; }
    public R getR(){ return r; }
    public void setL(L l){ this.l = l; }
    public void setR(R r){ this.r = r; }
}
class customer{
    List<Pair<product,Integer>> cart; //=new ArrayList<product>();
    private String customerID;
    private int remainingFunds;

    public customer(String customerID,int funds){
        cart=new ArrayList<Pair<product,Integer>>();
        this.customerID=customerID;
        this.remainingFunds=funds;

    }
    public int getRemainingFunds(){
        return this.remainingFunds;
    }
    public String getCustomerID(){
       return this.customerID; 
    }
    public void checkoutCart(database myDatabase){
        for (int i = 0; i < cart.size(); i++) {
            int prevRemainingFunds=this.remainingFunds;
            Pair prevPair=cart.get(i);
            this.remainingFunds=myDatabase.sale(cart.get(i).getL(),cart.get(i).getR(),this.getRemainingFunds());
            if(remainingFunds<prevRemainingFunds){
                cart.remove(prevPair);
            }
        }
    }
    public void addFunds(int fundsToBeAdded){
        this.remainingFunds+=fundsToBeAdded;
        System.out.println("Success, funds added!");
    }
    public void addToCart(product productToBeAdded,int quantityDemanded){
        Pair<product,Integer> pair= new Pair<product,Integer>(productToBeAdded,quantityDemanded);
        if(quantityDemanded<=productToBeAdded.getUnits()){
            cart.add(pair);
            System.out.println("Success, product added to your cart!");
        }
        else
        System.out.println("The number of units demanded aren't available!");
    }
}
class main1{
    public static void main(String[] args) throws IOException{
        List<customer> customerList=new ArrayList<customer>();
        database myDatabase=new database();
        customer myCustomer=new customer("false", 0);
        BufferedReader bro = null;
        String strLine = "";
        try {
            bro = new BufferedReader( new FileReader("database.csv"));
            while( (strLine = bro.readLine()) != null){
                String[] databaseData=strLine.split(",");
                product productToBeAddedFromFile=new product(databaseData[0],databaseData[1],Integer.parseInt(databaseData[2]),Integer.parseInt(databaseData[3]));
                myDatabase.insert(productToBeAddedFromFile);
            }
        } catch (FileNotFoundException e) {
            System.err.println("Seems like no database file already exists, will create a new database!");
        } catch (IOException e) {
            System.err.println("Unable to read database file!");
        }
        try {
            bro = new BufferedReader( new FileReader("customer.csv"));
            while( (strLine = bro.readLine()) != null){
                String[] customerData=strLine.split(",");
                customer customerToBeAddedFromFile=new customer(customerData[0],Integer.parseInt(customerData[1]));
                int customerCartSize=Integer.parseInt(customerData[2]);
                for(int i=0;i<customerCartSize;i++){
                    String productName=customerData[2*i+3];
                    int quantityDemanded=Integer.parseInt(customerData[2*i+4]);
                    product productToBeAddedToCart=myDatabase.search(productName);
                    if(productToBeAddedToCart.getProductName().equals("false")){
                        System.out.println("Some of the products in customers' cart have been removed from database, they will be removed from customers' cart automatically,product: "+productName);

                    }
                    else{
                        Pair<product,Integer> pair= new Pair<product,Integer>(productToBeAddedToCart,quantityDemanded);
                        if(quantityDemanded<=productToBeAddedToCart.getUnits()){
                            customerToBeAddedFromFile.cart.add(pair);
                            //System.out.println("Success, product added to your cart!");
                        }
                        else
                        System.out.println("Some products have been removed from customer "+customerToBeAddedFromFile.getCustomerID() +"'s " +"cart because of unavailability!");
                        //customerToBeAddedFromFile.cart.add(pair);
                    }
                }
                customerList.add(customerToBeAddedFromFile);
            }
        } catch (FileNotFoundException e) {
            System.err.println("Seems like no customer database file already exists, will create a new database!");
        } catch (IOException e) {
            System.err.println("Unable to read database file!");
        }
        //customer myCustomer=new customer("1", 0);
        while(true){

            System.out.println("Enter 1 to use as admin, enter 0 to use as customer, any other integer to quit");
            Scanner intScanner=new Scanner(System.in);
            int whatTheUserWants=intScanner.nextInt();
            //administrator case
            if(whatTheUserWants==1){
                while(true){
                    System.out.println("Enter:\n 1: to insert product/category \n 2: delete product/category \n 3: Search for a product \n 4: Modify a product \n Any other integer: Exit as administrator");
                    int userChoice=intScanner.nextInt();
                    if(userChoice==1){
                        System.out.println("Enter the category");
                        BufferedReader brObject = new BufferedReader(new InputStreamReader(System.in));  
                        String category= brObject.readLine();
                        //String category=intScanner.nextLine();
                        System.out.println("Enter the subcategory");
                        String subcategory=brObject.readLine();
                        System.out.println("Enter the product name");
                        String productName=brObject.readLine();
                        myDatabase.insert(category+">"+subcategory, productName);
                    }
                    else if(userChoice==2){
                        System.out.println("Enter the category");
                        BufferedReader brObject = new BufferedReader(new InputStreamReader(System.in));  
                        String category= brObject.readLine();
                        //String category=intScanner.nextLine();
                        System.out.println("Enter the subcategory");
                        String subcategory=brObject.readLine();
                        System.out.println("Enter the product name, enter nothing if you want to delete the whole subcategory");
                        String productName=brObject.readLine();
                        if((productName.length()==0)){
                            myDatabase.delete(category+">"+subcategory);
                            //System.out.println("hello");
                        }
                        else
                        myDatabase.delete(category+">"+subcategory+">"+productName);
                        //myDatabase.delete(category+">"+subcategory+">"+productName);
                    }
                    else if(userChoice==3){
                        BufferedReader brObject = new BufferedReader(new InputStreamReader(System.in));  
                        System.out.println("Enter the product name you wish to search for");
                        String productName=brObject.readLine();
                        product returnedProduct=myDatabase.search(productName);
                        if(!(returnedProduct.getProductName().equals("false"))){
                            System.out.println("The path to the product is:\n"+returnedProduct.getSubcategory()+">"+returnedProduct.getProductName());
                            System.out.println("The number of units available are:"+returnedProduct.getUnits());
                            System.out.println("The price of the product is:"+returnedProduct.getPrice());
                            
                        }
                    }
                    else if(userChoice==4){
                        BufferedReader brObject = new BufferedReader(new InputStreamReader(System.in));  
                        System.out.println("Enter the product name you wish to modify");
                        String productName=brObject.readLine();
                        myDatabase.modify(productName);
                    }
                    else {
                        break;

                    }
                }
                
            }
            //customer case
            
            else if(whatTheUserWants==0){
                    
                    System.out.print("Enter your username");
                    int flag=0;
                    BufferedReader brObject1 = new BufferedReader(new InputStreamReader(System.in));  
                    String customerName= brObject1.readLine();
                    for (int i = 0; i < customerList.size(); i++) {
                        if(customerList.get(i).getCustomerID().equals(customerName)){
                            myCustomer=customerList.get(i);
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1){
                        System.out.println("Welcome Back!");

                    }
                    else{
                        System.out.println("Seems like it's your first visit to Amacon! Welcome!");
                        myCustomer=new customer(customerName,0);
                        customerList.add(myCustomer);
                    }

                    while(true){
                        System.out.println("Enter:\n 1: to add funds \n 2: add product to cart \n 3: checkout your cart\n Any other integer: Exit as customer \n ");
                        int userChoice=intScanner.nextInt();
                        if(userChoice==1){
                            System.out.println("Enter the amount of funds you wish to add");
                            int fundsToBeAdded=intScanner.nextInt();
                            myCustomer.addFunds(fundsToBeAdded);
                        }
                        else if(userChoice==2){
                            System.out.println("Enter the product's name");
                            BufferedReader brObject = new BufferedReader(new InputStreamReader(System.in));  
                            String productName= brObject.readLine();
                            product productToBeAdded=myDatabase.search(productName);
                            if(!(productToBeAdded.getProductName().equals("false"))){
                                System.out.println("The number of units available are:"+productToBeAdded.getUnits());
                                System.out.println("The price of the product is:"+productToBeAdded.getPrice());
                                System.out.println("Enter the number of units you would like to purchase");
                                int quantityDemanded=intScanner.nextInt();
                                myCustomer.addToCart(productToBeAdded,quantityDemanded);
                                
                            }
                        }
                        else if(userChoice==3){
                            myCustomer.checkoutCart(myDatabase);
                        }
                        else{
                            break;
                        }
                    }   


            }
            else{
                System.out.println("Have a good day!, exiting...");
                System.out.println("Revenue generated is:"+ myDatabase.getRevenue());
                try {
                    File file = new File("database.csv"); 
                    file.delete();
                    final Path path = Paths.get("database.csv");
                   Iterator<Map.Entry<String, List<product>>> it= myDatabase.databaseMap.entrySet().iterator();
                    while (it.hasNext()) {
                        Map.Entry<String, List<product>> pair = (Map.Entry<String, List<product>>)it.next();
                        List<product> productList =pair.getValue();
                        for (int i = 0; i < productList.size(); i++) {
                            product productToBeWritten=productList.get(i);
                            String toWriteToDatabaseFile=productToBeWritten.getSubcategory()+","+productToBeWritten.getProductName()+","+productToBeWritten.getPrice()+","+productToBeWritten.getUnits();
                            Files.write(path, Arrays.asList(toWriteToDatabaseFile), StandardCharsets.UTF_8,
                        Files.exists(path) ? StandardOpenOption.APPEND : StandardOpenOption.CREATE);
                        //it.remove(); // avoids a ConcurrentModificationException
                        }
                    }
                    file= new File("customer.csv");
                    file.delete();
                    final Path path1= Paths.get("customer.csv");
                    for (int i = 0; i < customerList.size(); i++) {
                        
                        customer customerToBeWritten=customerList.get(i);
                        String toWriteToDatabaseFile=customerToBeWritten.getCustomerID()+","+customerToBeWritten.getRemainingFunds()+","+customerToBeWritten.cart.size();
                        for (int j = 0; j < customerToBeWritten.cart.size(); j++) {
                            toWriteToDatabaseFile+=","+customerToBeWritten.cart.get(i).getL().getProductName()+","+customerToBeWritten.cart.get(i).getR();

                        }
                    Files.write(path1, Arrays.asList(toWriteToDatabaseFile), StandardCharsets.UTF_8,
                        Files.exists(path1) ? StandardOpenOption.APPEND : StandardOpenOption.CREATE);
                    }
                }

                
                catch (final IOException ioe) {
                    System.out.println("Some exception has occured while writing to database files!");
                }
                return;
            }
        }

    }
}