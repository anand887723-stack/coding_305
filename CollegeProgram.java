import java.util.HashMap;
import java.util.Map;

// Define an interface for participating hours
interface ParticipateHours {
    int getParticipatingHours(int courseHours);
}

// Abstract class Person implements the ParticipateHours interface
abstract class Person implements ParticipateHours {
    private String firstName;
    private String lastName;

    public Person(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String getFullName() {
        return firstName + " " + lastName;
    }

    // Abstract method to be implemented by subclasses
    public abstract String getTitle();
}

// Professor class inherits from Person
class Professor extends Person {
    public Professor(String firstName, String lastName) {
        super(firstName, lastName);
    }

    // Implement the getParticipatingHours method for Professors
    @Override
    public int getParticipatingHours(int courseHours) {
        return courseHours;
    }

    @Override
    public String getTitle() {
        return "Professor";
    }
}

// TA class inherits from Person
class TA extends Person {
    public TA(String firstName, String lastName) {
        super(firstName, lastName);
    }

    // Implement the getParticipatingHours method for TAs
    @Override
    public int getParticipatingHours(int courseHours) {
        return (courseHours > 4) ? 2 : 1;
    }

    @Override
    public String getTitle() {
        return "TA";
    }
}

// Student class inherits from Person
class Student extends Person {
    public Student(String firstName, String lastName) {
        super(firstName, lastName);
    }

    // Implement the getParticipatingHours method for Students
    @Override
    public int getParticipatingHours(int courseHours) {
        return courseHours;
    }

    @Override
    public String getTitle() {
        return "Student";
    }
}

public class CollegeProgram {
    public static void main(String[] args) {
        String input = "Professor Isaac Newton Physics 6 TA Marie Curie Physics 6 Professor Issac Newtonn Calculus 4 " +
                "Student Brad Pitt Physics 6 Student Will Smith Chemistry 6 TA Carl Gauss Calculus 3 " +
                "Professor Adam Smith Economics 3";

        // Split the input string into individual words
        String[] words = input.split(" ");

        // Create a map to store people with their total hours
        Map<String, Person> peopleMap = new HashMap<>();

        int currentIndex = 0;
        while (currentIndex < words.length) {
            String title = words[currentIndex];
            currentIndex++;
            String firstName = words[currentIndex];
            currentIndex++;
            String lastName = words[currentIndex];
            currentIndex++;
            String course = words[currentIndex];
            currentIndex++;
            int totalHours = Integer.parseInt(words[currentIndex]);
            currentIndex++;

            Person person;
            if (title.equals("Professor")) {
                person = new Professor(firstName, lastName);
            } else if (title.equals("TA")) {
                person = new TA(firstName, lastName);
            } else {
                person = new Student(firstName, lastName);
            }

            // Calculate participating hours and store in the map
            int participatingHours = person.getParticipatingHours(totalHours);
            peopleMap.put(person.getFullName(), person);

            // Skip to the next person's data
            currentIndex++;
        }

        // Print the results
        for (Map.Entry<String, Person> entry : peopleMap.entrySet()) {
            Person person = entry.getValue();
            String title = person.getTitle();
            String fullName = person.getFullName();
            int totalHours = person.getParticipatingHours(0);
            System.out.println(title + " " + fullName + " " + totalHours);
        }
    }
}
