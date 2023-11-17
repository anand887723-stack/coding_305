import java.util.Random;

public class ArrayAlgorithms {

    // Algorithm to find the sum of array elements
    public static int sum(int[] a, int n) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += a[i];
        }
        return result;
    }

    // Algorithm to find the maximum element in the array
    public static int max(int[] a, int n) {
        int maximum = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (a[i] > maximum) {
                maximum = a[i];
            }
        }
        return maximum;
    }

    public static void main(String[] args) {
        // Generate random values for the array
        int n = 10; // Change this value to the desired array size
        int[] array = new int[n];
        Random random = new Random();

        for (int i = 0; i < n; i++) {
            array[i] = random.nextInt(100); // Random values between 0 and 99
        }

        // Test the sum algorithm
        int sumResult = sum(array, n);
        System.out.println("Sum of array elements: " + sumResult);

        // Test the max algorithm
        int maxResult = max(array, n);
        System.out.println("Maximum element in the array: " + maxResult);
    }
}
