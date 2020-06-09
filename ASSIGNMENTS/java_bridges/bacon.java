//Adapted from the BRIDGES demo code here: http://bridgesuncc.github.io/Hello_World_Tutorials/Graph_AL.html
import java.util.*;
import java.lang.String;
import bridges.base.*;
import bridges.connect.*;
import bridges.data_src_dependent.ActorMovieIMDB;

public class bacon {
	private static Color distance_to_color(int distance) {
		Color retval;
		//ROYGBIV
		switch (distance) {
			case 0:
				retval = new Color(255,0,0,1);
				return retval;
			case 1:
				retval = new Color(255,128,0,1);
				return retval;
			case 2:
				retval = new Color(255,255,0,1);
				return retval;
			case 3:
				retval = new Color(0,255,0,1);
				return retval;
			case 4:
				retval = new Color(0,255,255,1);
				return retval;
			case 5:
				retval = new Color(0,0,255,1);
				return retval;
			case 6:
				retval = new Color(75,0,130,1);
				return retval;
			default:
				retval = new Color(238,130,238,1);
				return retval;
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);

		// initialize Bridges
		//TODO: PUT YOUR INFO IN HERE
		//TODO: WE WILL SUBSTITUTE IN MINE FOR THE AUTOGRADER
		Bridges bridges = new Bridges(34, "mzamudio", "614923477058");

		// create an adjacency list based graph
		GraphAdjListSimple<String> g = new GraphAdjListSimple<String>();

		ArrayList<ActorMovieIMDB>  actor_movie_data = (ArrayList<ActorMovieIMDB>) bridges.getActorMovieIMDBData(1814);
		HashSet<String> actors = new HashSet<String>(); //Hashtable implementing the Set interface
		HashSet<String> movies = new HashSet<String>();
		//System.out.print("IMDB records loaded: ");
		//System.out.println(actor_movie_data.size());
		for (int k = 0; k < actor_movie_data.size(); k++) {
			String actor = actor_movie_data.get(k).getActor();
			String movie = actor_movie_data.get(k).getMovie();
			//System.out.println(actor + " was in " + movie);

			//First see if the actor or movie is in our graph
			Element e_actor = g.getVertex(actor);
			if (e_actor == null) {
				g.addVertex(actor, "");
				e_actor = g.getVertex(actor);
				e_actor.getVisualizer().setShape("diamond");//All actors are diamonds
				actors.add(actor); //Add to our list of actors
			}
			Element e_movie = g.getVertex(movie);
			if (e_movie == null) {
				g.addVertex(movie, "");
				e_movie = g.getVertex(movie);
				e_movie.getVisualizer().setOpacity(0.5f);
				movies.add(movie); //Add to our list of movies
			}
			g.addEdge(actor, movie, 1);
			g.addEdge(movie, actor, 1);
		}
		System.out.println("We know the following actors:");
		for (String s : actors) System.out.println(s);

		String name;
		Element starting_element;
		while (true) {
			System.out.println("Which actor would you like to compute the Bacon distance for?");
			name = in.nextLine();
			starting_element = g.getVertex(name);
			if (starting_element == null) {
				System.out.println("That name was not found!");
				continue;
			}
			if (movies.contains(name)) { //Hashtable lookup
				System.out.println("That is a movie, not an actor!");
				continue;
			}
			if (!actors.contains(name)) {
				System.out.println("This shouldn't happen, but the actor wasn't found!");
				continue;
			}

			// set a title for the visualization
			bridges.setTitle("BaconGraph for " + name);

			break;
		}
		//We will do ROYGBIV to color distance from our starting actor
		//Movies of our starting actor will be colored gold
		int distance = 0;
		starting_element.getVisualizer().setColor(distance_to_color(distance));

		//We keep track of all actors we need to process and have processed, so we don't duplicate effort
		//The integer is how far away they are from our starting actor
		LinkedHashMap<String,Integer> actors_processed  = new LinkedHashMap<String,Integer>();
		LinkedHashMap<String,Integer> movies_processed  = new LinkedHashMap<String,Integer>();
		//Queue of all actors and movies to process
		LinkedHashMap<String,Integer> actors_to_process = new LinkedHashMap<String,Integer>();
		LinkedHashMap<String,Integer> movies_to_process = new LinkedHashMap<String,Integer>();

		//Get a linked list of all nodes from our starting actor
		SLelement<Edge<String, String>> head = g.getAdjacencyList().get(name);
		//START OF THE MEAT
		for (SLelement<Edge<String, String>> ptr = head; ptr != null; ptr = ptr.getNext()) {
			//get the name of the other person
			String other = ptr.getValue().getVertex();
			//Element is the BRIDGES rendering object - You use it to control the color and shape of the node getting rendered
			Element e_other = g.getVertices().get(other);
			if (movies.contains(other)) { //It's a movie on the other side
				e_other.getVisualizer().setColor(distance_to_color(distance));
				movies_to_process.put(other,distance+1); //Add it to our queue to process
			}
			else System.out.println("Error: an actor was connected to an actor");
		}
		//THE MEAT OF THE TODO
		actors_processed.put(name,0); //Add our starting name to the processed list
		System.out.println("All of " + name + "'s movies are:");
		for (String s : movies_to_process.keySet()) System.out.println(s);

		distance = 1;
		while (movies_to_process.size() > 0) {
			for (String s: movies_to_process.keySet()){
			//YOU: Process all movies in the queue, then all actors in the queue and repeat
			SLelement<Edge<String, String>> actor_head = g.getAdjacencyList().get(s);	
			//Hint: Look above to see how to do this
			for (SLelement<Edge<String, String>> ptr = actor_head; ptr != null; ptr = ptr.getNext()) {
			//YOU: Check for duplicates
				
			}
			//YOU: Ok, it's a new actor, let's put it in the queue and color it by distance
			//e_other.getVisualizer().setColor(distance_to_color(distance));
		}
		movies_to_process.clear(); //We've processed all movies, so clear the queue
		//Now process all actors in the queue
		for (String s : actors_to_process.keySet()) {
			//YOU: Basically the same as above, but for actors
		}
		actors_to_process.clear(); //We've processed all actors, so clear the queue
		distance++;
	}
	//Now that we're done, print the bacon distance to each other actor
	System.out.println("The Bacon distance to each actor is:");
	for (String s : actors_processed.keySet()) {
		System.out.println(s + " is " + actors_processed.get(s) + " away from " + name);
	}

	// Pass the graph object to BRIDGES
	bridges.setDataStructure(g);

	// Finaly we call the visualize function
	bridges.visualize();
}
}

