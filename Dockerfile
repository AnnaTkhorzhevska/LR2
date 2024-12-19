# Використовуємо базовий образ
FROM ubuntu:latest

# Оновлення пакетів та встановлення необхідних залежностей
RUN apt-get update && \
    apt-get install -y libmicrohttpd-dev

# Копіюємо скомпільований сервер у контейнер
COPY src/server /app/server

# Встановлюємо робочу директорію
WORKDIR /app

# Відкриваємо порт 8080 для HTTP-сервера
EXPOSE 8080

# Команда для запуску сервера
CMD ["./server"]
