****************************************
Author: Matt Schwartz
Created: Jun 26 2011
Header files: Network-Header, UPC-Header
C Files: Item-Database, Scanner, Terminal
****************************************
Item-Database: Ideally runs constantly, source of list of products and associated UPC number, price, and tobacco/alcohol flags.  Given UPC, will perform a look-up for Terminals
Terminal: Given the UPC number from scanner, will request a look-up from Item-Database via UNIX network connection using TCP and will keep track of total cost for transaction
Scanner: Simulator program which at random time intervals writes random UPC numbers to stdout.  In an ideal scenario, the Scanner would be an actual scanning device; i.e., hardware
