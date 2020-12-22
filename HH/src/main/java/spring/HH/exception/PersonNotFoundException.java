package spring.HH.exception;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class PersonNotFoundException extends RuntimeException {

    private static final String MESSAGE = "Person entity is not exist.";

    public PersonNotFoundException() {
        super(MESSAGE);
        log.error(MESSAGE);
    }
}
