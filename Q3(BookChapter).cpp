#include <iostream>
#include <vector>

struct Subsection {
    std::string title;
};

struct Section {
    std::string title;
    std::vector<Subsection> subsections;
};

struct Chapter {
    std::string title;
    std::vector<Section> sections;
};

struct Book {
    std::string title;
    std::vector<Chapter> chapters;
};

void printNodes(const Book& book) {
    std::cout << "Book: " << book.title << std::endl;

    for (const auto& chapter : book.chapters) {
        std::cout << "Chapter: " << chapter.title << std::endl;

        for (const auto& section : chapter.sections) {
            std::cout << "Section: " << section.title << std::endl;

            for (const auto& subsection : section.subsections) {
                std::cout << "Subsection: " << subsection.title << std::endl;
            }
        }
    }
}

int main() {
    Book book;
    book.title = "Sample Book";

    // Chapter 1
    Chapter chapter1;
    chapter1.title = "Chapter 1";

    // Section 1.1
    Section section11;
    section11.title = "Section 1.1";

    Subsection subsection111;
    subsection111.title = "Subsection 1.1.1";
    section11.subsections.push_back(subsection111);

    Subsection subsection112;
    subsection112.title = "Subsection 1.1.2";
    section11.subsections.push_back(subsection112);

    chapter1.sections.push_back(section11);

    // Section 1.2
    Section section12;
    section12.title = "Section 1.2";

    Subsection subsection121;
    subsection121.title = "Subsection 1.2.1";
    section12.subsections.push_back(subsection121);

    Subsection subsection122;
    subsection122.title = "Subsection 1.2.2";
    section12.subsections.push_back(subsection122);

    chapter1.sections.push_back(section12);

    book.chapters.push_back(chapter1);

    // Chapter 2
    Chapter chapter2;
    chapter2.title = "Chapter 2";

    // Section 2.1
    Section section21;
    section21.title = "Section 2.1";

    Subsection subsection211;
    subsection211.title = "Subsection 2.1.1";
    section21.subsections.push_back(subsection211);

    Subsection subsection212;
    subsection212.title = "Subsection 2.1.2";
    section21.subsections.push_back(subsection212);

    chapter2.sections.push_back(section21);

    book.chapters.push_back(chapter2);

    // Print all the nodes in the tree
    printNodes(book);

return 0;
}
