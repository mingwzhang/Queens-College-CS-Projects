//Mingwei Zhang (23510667)

class Member {
	// Basic details for each member
    String firstName, lastName, id;
    int age;
    boolean livesInNewYork;

    /**
     * Constructor to set up a new member.
     * @param firstName Member's first name
     * @param lastName Member's last name
     * @param id Unique membership ID
     * @param age Member's age
     * @param livesInNewYork True if the member lives in New York, false otherwise
     */
    
    public Member(String firstName, String lastName, String id, int age, boolean livesInNewYork) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.id = id;
        this.age = age;
        this.livesInNewYork = livesInNewYork;
    }

    /**
     * Converts Member object data into a formatted string.
     */
    @Override
    public String toString() {
        return firstName + "|" + lastName + "|" + id + "|" + age + "|" + livesInNewYork;
    }
}