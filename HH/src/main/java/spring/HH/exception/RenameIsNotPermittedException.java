package spring.HH.exception;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class RenameIsNotPermittedException extends RuntimeException {

    private static final String MESSAGE = "Change name is not accepted.";

    public RenameIsNotPermittedException() {
        super(MESSAGE);
        log.error(MESSAGE);
    }
}
