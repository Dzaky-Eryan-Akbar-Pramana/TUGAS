#include <iostream>
using namespace std;

// Fungsi untuk menampilkan papan permainan
void displayBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";  // Tambahkan garis vertikal antar sel
            }
        }
        cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;  // Tambahkan garis horizontal antar baris
        }
    }
}

// ... (fungsi lainnya tetap sama)

// Fungsi untuk mengecek apakah terdapat pemenang
char checkWinner(char board[3][3]) {
    // Cek baris dan kolom
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0]; // Pemenang di baris i
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i]; // Pemenang di kolom i
        }
    }

    // Cek diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0]; // Pemenang di diagonal utama
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2]; // Pemenang di diagonal seondary
    }

    return ' '; // Tidak ada pemenang
}

// Fungsi untuk memeriksa apakah permainan seri
bool isGameTie(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // Masih ada sel kosong, permainan belum seri
            }
        }
    }
    return true; // Semua sel terisi, permainan seri
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char currentPlayer = 'X';

    do {
        // Menampilkan papan permainan
        displayBoard(board);

        // Meminta input dari pemain
        cout << "Pemain " << currentPlayer << ", masukkan baris (0-2) dan kolom (0-2): ";
        cin >> row >> col;

        // Memeriksa apakah langkah valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Langkah tidak valid. Coba lagi." << endl;
            continue;
        }

        // Menetapkan simbol pemain ke dalam papan permainan
        board[row][col] = currentPlayer;

        // Memeriksa pemenang
        char winner = checkWinner(board);
        if (winner != ' ') {
            // Menampilkan papan permainan
            displayBoard(board);
            cout << "Pemain " << winner << " menang!" << endl;
            break;
        }

        // Memeriksa apakah permainan seri
        if (isGameTie(board)) {
            // Menampilkan papan permainan
            displayBoard(board);
            cout << "Permainan seri!" << endl;
            break;
        }

        // Ganti giliran pemain
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    // Opsi untuk bermain lagi
    char playAgain;
    cout << "Apakah Anda ingin bermain lagi? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        // Atur ulang papan permainan
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        main(); // Panggil main() untuk memulai permainan lagi
    }

    return 0;
}
