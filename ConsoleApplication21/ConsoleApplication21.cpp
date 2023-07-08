// ConsoleApplication21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

struct Video {
    string title;
    string director;
    string genre;
    int popularity_rating;
    double price;
};

class VideoLibrary {
private:
    vector<Video> videos;

public:
    void addVideo(const Video& video) {
        videos.push_back(video);
    }

    void searchByTitle(const string& search_title) {
        cout << "Результати пошуку за назвою \"" << search_title << "\":" << endl;

        for (const auto& video : videos) {
            if (video.title == search_title) {
                displayVideo(video);
            }
        }

        cout << endl;
    }

    void searchByGenre(const string& search_genre) {
        cout << "Результати пошуку за жанром \"" << search_genre << "\":" << endl;

        for (const auto& video : videos) {
            if (video.genre == search_genre) {
                displayVideo(video);
            }
        }

        cout << endl;
    }

    void searchByDirector(const string& search_director) {
        cout << "Результати пошуку за режисером \"" << search_director << "\":" << endl;

        for (const auto& video : videos) {
            if (video.director == search_director) {
                displayVideo(video);
            }
        }

        cout << endl;
    }

    void findMostPopularMovieByGenre(const string& search_genre) {
        cout << "Найпопулярніший фільм у жанрі \"" << search_genre << "\":" << endl;

        int max_rating = 0;
        Video most_popular_movie;

        for (const auto& video : videos) {
            if (video.genre == search_genre && video.popularity_rating > max_rating) {
                max_rating = video.popularity_rating;
                most_popular_movie = video;
            }
        }

        if (max_rating > 0) {
            displayVideo(most_popular_movie);
        }
        else {
            cout << "Фільми в жанрі \"" << search_genre << "\" не знайдені." << endl;
        }

        cout << endl;
    }

    void displayAllVideos() {
        if (videos.empty()) {
            cout << "Немає жодного запису про фільми." << endl << endl;
        }
        else {
            cout << "Всі записи про фільми:" << endl;

            for (const auto& video : videos) {
                displayVideo(video);
            }
        }

        cout << endl;
    }

private:
    void displayVideo(const Video& video) {
        cout << "Назва фільму: " << video.title << endl;
        cout << "Режисер: " << video.director << endl;
        cout << "Жанр: " << video.genre << endl;
        cout << "Рейтинг популярності: " << video.popularity_rating << endl;
        cout << "Ціна перегляду: " << video.price << endl << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    VideoLibrary videoLibrary;

    
    videoLibrary.addVideo({ "Фільм 1", "Режисер 1", "Жанр 1", 8, 9.99 });
    videoLibrary.addVideo({ "Фільм 2", "Режисер 2", "Жанр 1", 7, 8.99 });
    videoLibrary.addVideo({ "Фільм 3", "Режисер 3", "Жанр 2", 9, 12.99 });
    videoLibrary.addVideo({ "Фільм 4", "Режисер 4", "Жанр 1", 6, 7.99 });

    
    videoLibrary.searchByTitle("Фільм 1");

   
    videoLibrary.searchByGenre("Жанр 1");

    
    videoLibrary.searchByDirector("Режисер 3");

    
    videoLibrary.findMostPopularMovieByGenre("Жанр 1");

    
    videoLibrary.displayAllVideos();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
