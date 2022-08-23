#ifndef EXAMPLES_H
#define EXAMPLES_H

/**
 * @brief Использование setlocale с wstring
 *
 * @details
 * Плюсы:
 * - невилируются присутствием минуса
 * Минусы:
 * - кракозябры при считывании с входного потока (хотя почему-то популярный способ (-_-#))
 */
void example1();

/**
 * @brief Использование SetConsoleCP и локальных однобитных кодировок с string
 *
 * @details
 * Плюсы:
 * - работает без проблем и на линуксе и на винде
 * - используются стандартные string
 * Минусы:
 * - string неправильно считают число символов на линуксе
 * - приходится оборачивать константные строки
 *
 * @see
 * <a href="https://ru.stackoverflow.com/a/117230">
 * На ru.stackoverflow
 * </a>
 *
 * @see
 * <a href="https://docs.microsoft.com/en-us/windows/win32/intl/code-page-identifiers">
 * Таблица кодировок для винды
 * </a>
 */
void example2();

/**
 * @brief Использование _setmode - UTF-16 кодировки и wstring
 *
 * @details
 * Плюсы:
 * - wstring правильно считает число символов
 * Минусы:
 * - баг с сохранением '\n' при считывании getline (в win), надо после вызова очищать поток (причем про это 0 инфы (-_-#))
 * - надо везде использовать w функции (wcin, wprintf,...)
 * - wstring массово критикуют (потому что на винде это 2 байта, а на линуксе 4, и прочее). См ссылку
 *
 * @bug qDebug() перестает работать для выходного потока (в win): "Invalid parameter passed to C runtime function."
 * Полагаю причина в том, что Qt использует narrow функции в win (cм ссылку).
 *
 * @bug QTextStream перестает работать для выходного потока (в win/linux).
 * Почему не работает в linux хз...
 *
 * @see
 * <a href="https://stackoverflow.com/a/11107667">
 * Почему стоит избегать wstring
 * </a>
 *
 * @see
 * <a href="https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/setmode?view=msvc-170">
 * Use of a narrow print function on a Unicode mode stream triggers an assert.
 * </a>
 */
void example3();

#endif // EXAMPLES_H
