# **Oregon Trail Game**  

## **Description**  
Experience the historical journey of the Oregon Trail in this terminal-based game! Manage resources, make strategic decisions, and survive random events to reach your destination.  
- **Features**:  
  - Resource management: Food, water, oxen, and supplies.  
  - Random events: Encounter illnesses, broken wagons, bandits, and more.  
  - Milestones: Progress through various checkpoints to complete the trail.  
  - Replayability: Different outcomes based on your decisions.  

## **How to Run**  

### **Prerequisites**  
- A C++ compiler (e.g., `g++` from GCC).  
- A terminal or command prompt.  
- All source files in the same directory:  
  - `project3.cpp` (main file)  
  - `events.h`, `event.cpp`  
  - `milestones.h`, `milestone.cpp`  
  - `supplies.h`, `supply.cpp`  
  - `players.h`, `player.cpp`  

### **Instructions**  

1. **Navigate to the Project Directory**:  
   Open a terminal and go to the directory containing the project files.  
   ```bash
   cd /path/to/project
   ```

2. **Compile the Code**:  
   Run the following command to compile all source files into an executable:  
   ```bash
   g++ -o oregonTrail project3.cpp event.cpp supply.cpp player.cpp milestone.cpp 
   ```

3. **Run the Game**:  
   After successful compilation, execute the program using:  
   ```bash
   ./oregonTrail
   ```

4. **Follow the In-Game Instructions**:  
   Make choices as prompted, manage your resources, and try to survive the Oregon Trail!  

### **Optional**:  
To clean up the directory, remove the executable after playing:  
```bash
rm oregonTrail
```

## **File Descriptions**  
- **`project3.cpp`**: Contains the main function to start the game.  
- **`events.h` / `event.cpp`**: Defines and handles all events on the trail.  
- **`milestones.h` / `milestone.cpp`**: Manages progress through checkpoints.  
- **`supplies.h` / `supply.cpp`**: Tracks and updates inventory.  
- **`players.h` / `player.cpp`**: Represents the player and party members.  

