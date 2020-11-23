package cinema.controller;

import java.util.List;
import java.util.Optional;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import cinema.persistence.entity.Movie;
import cinema.service.IMovieService;

@RestController
@RequestMapping("/api/movie")
public class MovieController {
	
	@Autowired
	IMovieService movieService;
	
	@GetMapping
	@ResponseBody
	public List<Movie> allMovies() {
		return movieService.getAllMovies();
	}
	
	@GetMapping("/{id}")
	@ResponseBody
	public Optional<Movie> movieById(@PathVariable("id") int idMovie) {
		return movieService.getMovieById(idMovie);
	}
	
	@GetMapping("/byTitle")
	@ResponseBody
	public Set<Movie> movieByPartialTitle(@RequestParam("t") String partialTitle) {
		return movieService.getMovieByPartialTitle(partialTitle);
	}
	
	@GetMapping("/byDirector")
	@ResponseBody
	public Set<Movie> findByDirector(@RequestParam("d") int idDirector){
		return movieService.getMoviesByDirector(idDirector);
	}
	
	@GetMapping("/byActor")
	@ResponseBody
	public Set<Movie> findByActor(@RequestParam("a") int idActor){
		return movieService.getMoviesByActor(idActor);
	}
	
	@PostMapping
	@ResponseBody
	public Movie addMovie(@RequestBody Movie movie) {
		// TODO
		return movie;
	}

	@PutMapping("/modify")
	@ResponseBody
	public Optional<Movie> modifyMovie(@RequestBody Movie movie) {
		return Optional.empty();
	}
	
	@PutMapping("/addActor")
	public Optional<Movie> addActor(@RequestParam("a") int idActor, @RequestParam("m") int idMovie) {
		return Optional.empty();
	}
	
	@PutMapping("/setDirector")
	public Optional<Movie> setDirector(@RequestParam("d") int idDirector, @RequestParam("m") int idMovie) {
		return Optional.empty();
	}
	
	
	@DeleteMapping("/{id}")
	@ResponseBody
	public Optional<Movie> deleteMovie(@PathVariable("id") int idMovie) {
		// TODO  
		return Optional.empty();
	}
}
