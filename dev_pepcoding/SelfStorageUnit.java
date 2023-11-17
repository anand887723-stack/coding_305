import java.util.Arrays;

public class SelfStorageUnit {

    private Item[] items;

    /* Constructors */

    public SelfStorageUnit() {
        // Initialize an empty SelfStorageUnit
        items = new Item[0];
    }

    public SelfStorageUnit(Item[] items) {
        // Initialize a SelfStorageUnit with non-null Items from the given array
        this.items = Arrays.stream(items)
                           .filter(item -> item != null)
                           .toArray(Item[]::new);
    }

    /* Modifiers */

    public boolean add(Item e) {
        // Add an Item to this SelfStorageUnit if e is not null
        if (e != null) {
            items = Arrays.copyOf(items, items.length + 1);
            items[items.length - 1] = e;
            return true;
        }
        return false;
    }

    public boolean addAll(Item[] items) {
        // Add all non-null Items from the given array to this SelfStorageUnit
        boolean added = false;
        for (Item item : items) {
            if (add(item)) {
                added = true;
            }
        }
        return added;
    }

    public void empty() {
        // Empty this SelfStorageUnit
        items = new Item[0];
    }

    public void keepOnlyItemsWith(int maxItemWeightInGrammes) {
        // Remove Items from this SelfStorageUnit whose weight is greater than the specified maximum weight
        items = Arrays.stream(items)
                      .filter(item -> item.getWeight() <= maxItemWeightInGrammes)
                      .toArray(Item[]::new);
    }

    /* Accessors */

    public int numberOfItems() {
        // Return the number of non-null Items in this SelfStorageUnit
        return items.length;
    }

    public int totalWeightInGrammes() {
        // Return the total weight of the Items in this SelfStorageUnit
        return Arrays.stream(items).mapToInt(Item::getWeight).sum();
    }

    public double averageWeightInGrammes() {
        // Return the average weight of the (non-null) Items in this SelfStorageUnit
        if (items.length == 0) {
            return -1.0; // No items in the SelfStorageUnit
        }
        return (double) totalWeightInGrammes() / items.length;
    }

    public Item greatestItem() {
        // Return the greatest Item in this SelfStorageUnit based on natural ordering
        return Arrays.stream(items)
                      .max(Item::compareTo)
                      .orElse(null);
    }

    public SelfStorageUnit makeNewUnitWith(int maxItemWeightInGrammes) {
        // Return a new SelfStorageUnit with Items whose weight is less than or equal to the specified maximum weight
        Item[] newItems = Arrays.stream(items)
                                .filter(item -> item.getWeight() <= maxItemWeightInGrammes)
                                .toArray(Item[]::new);
        return new SelfStorageUnit(newItems);
    }

    @Override
    public String toString() {
        // Return a string representation of this SelfStorageUnit
        return Arrays.toString(items);
    }

    /* Class methods */

    public static SelfStorageUnit heaviestUnit(SelfStorageUnit[] storageUnits) {
        // Return the SelfStorageUnit with the highest total weight among the given array
        return Arrays.stream(storageUnits)
                      .filter(storageUnit -> storageUnit != null)
                      .max((unit1, unit2) -> Integer.compare(unit1.totalWeightInGrammes(), unit2.totalWeightInGrammes()))
                      .orElse(null);
    }
}
