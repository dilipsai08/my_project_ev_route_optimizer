### **Best EV Route Finder**



##### **problem statement**



As electric vehicle (EV) adoption increases, drivers face a challenge that traditional navigation systems don't fully solve.



Unlike petrol vehicles, EVs have:



* Limited battery capacity
* Different charging speeds
* Limited charging infrastructure
* Waiting times at charging stations
* Different charging costs



A route that is the shortest by distance is often not the fastest or cheapest for an EV.



The objective is to build an engine that computes the optimal journey by considering all these constraints.



##### **Objective**



we should find the shortest path from the source to the destination.

1. We should return the shortest path (like A-->B-->C-->D)
2. We should return the journey distance from the source to the destination
3. fist we should find the look for the destination if we can reach with the current charge then go for it 
4. if we can't reach the destination, we should find the nearby/optimised charging station and add to the path 
5. at the result we should return the optimised path with journey distance, travelling time, charging time, total journey time.
6. the input is the current charging %, remaining range which is displayed by the EV, Range can be covered up on full charge of EV, source and the destination.