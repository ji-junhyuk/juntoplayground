package spring.HH.controller.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import java.time.LocalDate;

@Data
@NoArgsConstructor
@AllArgsConstructor(staticName = "of")
public class PersonDto {

    @NotBlank(message = "Name is necessary.")
    private String name;
    private String hobby;
    private String address;
    private LocalDate birthday; //Birthday birthday, return type (year, month, day)...
    private String job;
    private String phoneNumber;
}
