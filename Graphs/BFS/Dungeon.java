
// problem statement - https://open.kattis.com/problems/dungeon

package project0;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Dungeon {
	public static void main(String args[]) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//number of rows
		int R = Integer.parseInt(br.readLine());
		
		// number of columns
		int C = Integer.parseInt(br.readLine());
		
		//matrix representing the dungeon
		char matrix[][] = new char[R][C];
		
		//this will store source coordinate from where we will start our BFS.
		int sourceRow_coordinate = 0;;
		int sourceCol_coordinate= 0;
		
		
		for(int i=0;i<R;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int j=0;
			while(st.hasMoreTokens()) {
				matrix[i][j] = (st.nextToken()).charAt(0);
				if(matrix[i][j] == 'S'){
					sourceRow_coordinate = i;
					sourceCol_coordinate = j;
				}
				j++;
			}
		}
		
		// queues to store the row and col coordinates of the grid.
		Queue<Integer> row_coordinates = new LinkedList<>();
		Queue<Integer> col_coordinates = new LinkedList<>();
		
		// row and col vectors to go up, down, left and right the grid.
		int dr[] = {1,-1,0,0};
		int dc[] = {0,0,1,-1};
		
		
		//this will keep track if a location is visited or not.
		boolean visited[][] = new boolean[R][C];
		
		
		//check if we reached the end or not.
		boolean reachedEnd = false;
		
		// variables used
		int moveCount = 0;
		int nodes_left_in_layer = 1;
		int nodes_in_next_layer = 0;
		
		
		row_coordinates.add(sourceRow_coordinate);
		col_coordinates.add(sourceCol_coordinate);
		visited[sourceRow_coordinate][sourceCol_coordinate] = true;
		
		while(!row_coordinates.isEmpty()) { // or !col_coordinates.isEmpty()
		
			int currRow = row_coordinates.poll();
			int currCol = col_coordinates.poll();
			
			//if reached the end break out of the loop.
			if(matrix[currRow][currCol] == 'E') {
				reachedEnd = true;
				break;
			}
			
			// exploring other neighbors 
			for(int i=0;i<4;i++) {
				int rr = currRow +dr[i];
				int cc = currCol +dc[i];
				
				// checking for border case
				if(rr<0 || cc < 0) {
					continue;
				}
				if(rr>=R || cc>=C) {
					continue;
				}
				
				// if the node is already visited, skip.
				if(visited[rr][cc] == true) {
					continue;
				}
				
				// if the node is blocked ie '#', skip.
				if(matrix[rr][cc] == '#') {
					continue;
				}
				
				//add the unvisited node to the queue and visited to true.
				row_coordinates.add(rr);
				col_coordinates.add(cc);
				visited[rr][cc] = true;
				nodes_in_next_layer ++;
			}
			
			nodes_left_in_layer --;
			
			if(nodes_left_in_layer == 0) {
				nodes_left_in_layer = nodes_in_next_layer;
				nodes_in_next_layer = 0;
				moveCount +=1;
			}	
		}
		
		
		if(reachedEnd) {
			System.out.println(moveCount);
		}
		else {
			System.out.println(-1);
		}
		
		
		
	}
}
