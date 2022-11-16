// 1) Download mysql connector
// Jar File Link : https://jar-download.com/artifacts/mysql/mysql-connector-java
// Version 8.0.30
// 2) On Ecplise Create Java Project
// 3) Add a package mysqlConnectivity in project
// 4) Add Class Connectivity in package
// 5) Paste Below Code.

package mysqlConnectivity;
import java.util.*;
import java.sql.*;

public class Connectivity {
	public static void main(String args[]) {
		try {
			
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://10.10.10.108:3306/te31410_db", "te31410", "te31410");
			
			PreparedStatement ps = null;
			int ch = 0;
			Scanner sc = new Scanner(System.in);
			int sal, empid;
			String fname,lname, address;
			while(true) {
				System.out.println("1. Select\n2. Insert\n3. Update\n 4. Delete\n5. Exit\n");
				System.out.println("Enter your choice: ");
				ch = sc.nextInt();
				switch (ch) {
				case 1: {
					System.out.println("===Retrieving===\n");
					ps = con.prepareStatement("select * from Employe");
					ResultSet rs = ps.executeQuery();
					while (rs.next()) {
						empid = rs.getInt(1);
						fname = rs.getString(2);
						lname = rs.getString(3);
						sal = rs.getInt(4);
						address = rs.getString(5);
						System.out.println(empid + "\t" + fname + "\t" + lname + "\t" + sal + "\t" + address);
					}
					break;
				}
				case 2:
					System.out.println("===Inserting the entries===");
					System.out.print("Enter the empid: ");
					empid = sc.nextInt();
					System.out.print("Enter the fname: ");
					fname = sc.next();
					System.out.print("Enter the lname: ");
					lname = sc.next();
					System.out.print("Enter the salary: ");
					sal = sc.nextInt();
					System.out.print("Enter the address: ");
					address = sc.next();
					ps = con.prepareStatement("insert into Employe values ( "+ empid +", '"+ fname + "', '"+ lname +"', "+ sal +", '"+ address +"' )");
					ps.executeUpdate();
					break;
				case 3:
					System.out.println("===Updating Salary===");
					System.out.println("Enter the empid of Employe of which you want to update salary: ");
					empid = sc.nextInt();
					System.out.println("Enter the updated salary: ");
					sal = sc.nextInt();
					ps = con.prepareStatement("update Employe set salary = "+ sal +" where empid = "+ empid);
					ps.executeUpdate();
					break;
				case 4:
					System.out.println("===Deleting the Entries===");
					System.out.println("Enter the empid of Employe of which you want to update salary: ");
					empid = sc.nextInt();
					ps = con.prepareStatement("delete from Employe where empid = "+empid);
					ps.executeUpdate();
					break;
				case 5:
					con.close();
					sc.close();
					System.exit(0);
					break;
				default:
					break;
				}
			}
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
