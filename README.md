# EV Route Finder

## Overview
This project computes travel routes for electric vehicles between a source and destination. Rather than optimizing for distance alone, the routing engine accounts for battery capacity, charging station availability, and differing charging rates along the way.

## Methodology
The algorithm extends Dijkstra's shortest-path method into a two-dimensional state space, where each state represents both a location and the remaining battery range. Charging stops are modeled as additional edges that trade time for range, based on the charging rate at each station. Considering driving and charging time together, the algorithm finds the route with the lowest total journey time.

## Inputs
- Source and destination nodes
- Current battery level
- Maximum vehicle range on a full charge

## Outputs
- Optimal route, with charging stops indicated
- Total journey distance
- Driving time
- Charging time
- Total journey time (driving + charging)

## Demonstration
<img width="1180" height="643" alt="Screenshot 2026-07-10 150404" src="https://github.com/user-attachments/assets/c7cf9657-0312-469e-b3ca-5c005eba842e" />
<img width="1192" height="622" alt="Screenshot 2026-07-10 150433" src="https://github.com/user-attachments/assets/5eff8a1e-2311-4064-99bf-eded307f3c9d" />
<img width="1185" height="493" alt="Screenshot 2026-07-10 150503" src="https://github.com/user-attachments/assets/5a6d5b19-3a96-4f1a-a145-a2fe221610dc" />


