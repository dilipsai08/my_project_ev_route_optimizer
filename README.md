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
