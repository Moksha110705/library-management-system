class Library:
    def __init__(self, book_name, author, pages, price):
        self.book_name = book_name
        self.author = author
        self.pages = pages
        self.price = price

    def __str__(self):
        return f"{self.book_name}\t {self.author}\t {self.pages}\t {self.price}"


# Driver Code
if __name__ == "__main__":
    # Create an array of Library objects
    lib = []

    # Keep the track of the number of
    # of books available in the library
    count = 0
