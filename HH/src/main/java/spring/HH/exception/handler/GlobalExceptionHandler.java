package spring.HH.exception.handler;

import lombok.extern.slf4j.Slf4j;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestControllerAdvice;
import spring.HH.exception.PersonNotFoundException;
import spring.HH.exception.RenameIsNotPermittedException;
import spring.HH.exception.dto.ErrorResponse;

@Slf4j
@RestControllerAdvice
public class GlobalExceptionHandler {

    @ExceptionHandler(RenameIsNotPermittedException.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public ErrorResponse handleRenameNoPermittedException(RenameIsNotPermittedException ex) {
        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getMessage());
    }

    @ExceptionHandler(PersonNotFoundException.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public ErrorResponse handlePersonNotFoundException(PersonNotFoundException ex) {
        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getMessage());
    }

//    @ExceptionHandler(MethodArgumentNotValidException.class)
//    @ResponseBody(HttpStatus.BAD_REQUEST)
//    public ErrorResponse handleMethodArgumentNotValidException(MethodArgumentNotValidException ex) {
//        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getBindingResult().getFieldError().getDefaultMessage());
//    }

    @ExceptionHandler(RuntimeException.class)
    @ResponseStatus(HttpStatus.INTERNAL_SERVER_ERROR)
    public ErrorResponse handleRuntimeException(RuntimeException ex) {
        log.error("server error: {}", ex.getMessage(), ex);
        return ErrorResponse.of(HttpStatus.INTERNAL_SERVER_ERROR, "Unknown server error is occurred.");
    }
}
