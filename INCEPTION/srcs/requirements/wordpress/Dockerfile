# Base image (The penultimate stable version)
FROM alpine:3.16

# Port number
EXPOSE 9000

# Package installation
RUN set -eux && \
	apk update

# TODO: 필요한 소프트웨어 추가 설치

# Copy entrypoint script
COPY ./tools/entrypoint.sh .

RUN chmod +x entrypoint.sh

# Command to be executed
ENTRYPOINT ["./entrypoint.sh"]

# Health check
HEALTHCHECK --start-period=3s --interval=10s --timeout=30s --retries=5 CMD ps | grep docker-init

# Command to be executed (added to entrypoint)
CMD ["php-fpm8.1", "-F"]
