package spring.HH.exception;

import lombok.extern.slf4j.Slf4j;

@Slf4j
public class RenameIsNotPermittedException extends RuntimeException {

    private static final String MESSAGE = "Do not allow name changes.";
    public RenameIsNotPermittedException() {
        super(MESSAGE);
        log.error(MESSAGE);
    }
}
