# Assembly Line
The final project I completed for course OOP345(Object-Oriented Software Development using C++) in Seneca College during Summer 2019.
## Project Overview
The project simulates an assembly line that fills customer orders from inventory. Each customer order consists of a list of items that need to be filled. The line consists of a set of stations. Each station holds an inventory of items for filling customer orders and a queue of orders to be filled. Each station fills the next order in the queue if that order requests its item and that item is still in stock. A line manager moves the customer orders from station to station until all orders have been processed. Any station that has used all of the items in stock cannot fill any more orders. Orders become incomplete due to a lack of inventory at one or more stations. At the end of all processing, the line manager lists the completed orders and the orders that are incomplete. The figure below illustrates the classes that constitute the simulator and the process of filling orders as they move along the pipeline.
## Related C++ Topics
- design and code a composition
- work with vector and queue containers from the Standard Template Library
- work with class variables and functions
- parse a string into tokens 
- report and handle exceptions
- move objects from one container to another
